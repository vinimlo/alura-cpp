#include "printWordSpaces.hpp"
#include <iostream>
#include <map>
#include <string>

extern std::string secretWord;
extern std::map<char, bool> alreadyGuessed;

void printWordSpaces() {
  for (char letter : secretWord) {
    if (alreadyGuessed[letter])
      std::cout << letter << " ";
    else
      std::cout << "_ ";
  }
  std::cout << std::endl;
}
