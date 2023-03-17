export default class Parser {
  constructor(dictionaryURL) {
    this.dictionaryURL = dictionaryURL;
    this.list = {};
  }

  async initialize() {
    // Loads file from URL
    this.dictionary = await this.getContentFromFile(this.dictionaryURL);
    // Converts text to a string
    // Splits it at each line break (\n) to create array of words
    this.dictionary = this.dictionary.toString().split("\n");

    // Creates 'Alphabet' to store letter entries
    this.list = new Alphabet();

    // Loops through and fills alphabet list of entries
    await this.loadDictionary(this.list, this.dictionary);
  }

  loadDictionary(list, dictionary) {
    return new Promise((resolve, reject) => {
      // - Try/catch may be unnecessary... seems only possible failure would be
      //   from "Maximum call stack size exceeded," which may be solved with Promise,
      //   but would rather be safe.
      try {
        for (let word = 0; word < dictionary.length; ++word) {
          list.addWord(dictionary[word]);
        }
        resolve();
      } catch (reason) {
        reject(reason);
      }
    });
  }

  getContentFromFile(filename) {
    return new Promise((resolve, reject) => {
      fetch(filename)
        .then((res) => this.getResponse(filename, res))
        .then((content) => {
          resolve(content);
        })
        .catch((err) => {
          reject(`Error while attempting to get text file: ${err}`);
        });
    });
  }

  getResponse(filename, res) {
    return new Promise((resolve, reject) => {
      try {
        const ext = filename.substring(
          filename.lastIndexOf("."),
          filename.length
        );
        // Accepts either .txt or .json formatted dictionary files
        switch (ext) {
          default:
            reject("Unknown file type. Cannot read " + ext + " file type.");
          case ".txt":
            res.text().then((text) => resolve(text));
            break;
          case ".json":
            res.json().then((json) => resolve(json));
            break;
        }
      } catch (err) {
        reject("Cannot get response from file at: " + filename);
      }
    });
  }
}

class Alphabet {
  constructor() {
    // - Determines the charcode limits for each letter as to not process
    //   character entries in any dictionary
    this.charCodeMin = "a".charCodeAt(0) - 1;
    this.charCodeMax = this.charCodeMin + 28;

    this.branches = {}; // {"a": {"a": {}, "b": {} }, "b": {"a": {}, "b": {} } }
  }

  addBranch(letter) {
    this.branches[letter.letter] = letter;
  }

  // - Traverses the alphabetized list with each character in the word until
  //   either it reaches the end of the word, and a terminator is set, or there
  //   is no entry for the next character in the list, and a new letter-branch
  //   is created
  addWord(word) {
    let currentLetter = this;
    for (let i = 0; i < word.length; i++) {
      const char = word[i].toLowerCase();
      const charCode = char.charCodeAt(0);
      // Determines whether given character is in the english language
      if (charCode < this.charCodeMin || charCode > this.charCodeMax) return;
      let letter = currentLetter.branches[char];
      if (letter) {
        currentLetter = letter;
      } else {
        const newLetter = new Letter(char, currentLetter);
        currentLetter.addBranch(newLetter);
        currentLetter = newLetter;
      }
    }
    currentLetter.setTerminator();
  }

  // - Determines if a specified string is a valid word in the dictionary by
  //   traversing the alphabetized list and determining whether there is a match
  isValidPath(str) {
    let currentLetter = this;
    for (let i = 0; i < str.length; i++) {
      let letter = currentLetter.branches[str[i]];
      if (letter) {
        currentLetter = letter;
      } else {
        return false;
      }
    }
    if (currentLetter) return true;
  }
}

class Letter {
  constructor(letter, previous) {
    this.letter = letter;

    this.branches = {};
    this.prevLetter = previous;

    this.isFinal = false;
  }

  addBranch(letter) {
    this.branches[letter.letter] = letter; // branches["a"] = { "a": {}, "b", }
  }

  addPrev(letter) {
    this.prevLetter = letter;
  }

  setTerminator() {
    this.isFinal = true;
  }
}
