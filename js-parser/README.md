# Parser Module Info

#### Purpose

This file is a parser module I wrote for a larger cryptography project in Javascript. Its objective was to establish an alphabetized tree of letters, through which a search for a valid word can be easily made. It is initialized with a dictionary (sample dictionaries of 100,000 words, 10,000 words, and 1,000 words have all been provided under the `dictionaries/` directory).

#### Running

This code was taken from a larger project, built originally as a module, but is operable on its own. In order to run it, one must pass a valid `dictionaryURL` (of .txt or .json format) and then initialize the `Parser` by calling its asynchronous `initialize` method. Once initialized, one may call the `Parser.list.addWord()` method, providing a single argument containing the word to be added. One may also call upon the `Parser.list.isValidPath()` in order to validate whether the given string argument is a word.

#### Code

The Parser itself has 4 methods used to load a given dictionary (provided by the user): `initialize`, `loadDictionary`, `getContentFromFile`, and `getResponse`. The _initialize_ method is asynchronous and should be called after the Parser's construction and loads the dictionary file after **awaiting** the response from the _getContentFromFile_ method. It also constructs a new `Alphabet`, which is used to store the tree of words. It then goes on to load the dictionary into its _alphabet_, where each entry of the loaded dictionary is sorted into the tree structure of the _alphabet_.

The `Alphabet` consists of a list of `Letters`, each containing its own character and the _letters_ that branch off of it. When a new word is added, the `addWord` method will check if a character is part of the english alphabet, then traverse the branches until either there are no more branches, in which case a new letter is added, or until the end is reached, in which case the terminating _letter_ is set. After the words are added a user can use the `isValidPath` to submit a string and test if it matches any word in the dictionary. Each character in the string is searched for in the next frontier of the branches until there is a match or the character cannot be found, and the corresponding boolean is returned.
