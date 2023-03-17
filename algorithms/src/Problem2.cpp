#include <iostream>
#include <unordered_map>
#include "Problem2.hpp"

namespace Problem2 {
  // The given alphabet with their assigned encodings
  std::unordered_map<std::string, std::string> alphabet {
    {"a", "0"}, 
    {"b", "10"}, 
    {"c", "111"}, 
    {"d", "1101"}, 
    {"e", "1100"} 
  };

  // Receives the encoded word as a string of numbers called "word"
  // 1. Generates a substr to which each successive digit of the "word" is added
  // 2. Compares the substr to each entry within the alphabet 
  // 3. Upon match, adds that letter to the message and clears the substr. 
  //    Otherwise, continues onto the next digit
  // 4. Repeats looping until finished with the entire word
  void RunDecipher(std::string word)
  {
    std::string substr;
    std::string msg;
    for (size_t i = 0; i < word.length(); ++i) {
      substr.push_back(word.at(i));

      for (auto it : alphabet) {
        if (substr == it.second) {
          msg.append(it.first);
          substr = "";
          continue;
        }
      }
    }
    std::cout << msg << std::endl;
  }

  // Receives the word to be encoded as a string of numbers called "word"
  // 1. Generates a substr to which each successive digit of the "word" is added
  // 2. Attempts to find the substr within the alphabet
  // 3. If the iterator stops before reaching the end, it adds that letter to
  //    the message and clears the substr. Otherwise, it continues onto the next
  //    letter
  // 4. Repeats looping until finished with the entire word
  void RunEncipher(std::string word)
  {
    std::string substr;
    std::string msg;
    for (size_t i = 0; i < word.length(); ++i) {
      substr.push_back(word.at(i));
      auto it = alphabet.find(substr);
      if (it != alphabet.end()) {
        msg.append(it->second);
        substr = "";
      }
    }
    std::cout << msg << std::endl;
  }
}