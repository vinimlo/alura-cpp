#include "addWordsToFile.hpp"
#include "readFile.hpp"
#include "saveFile.hpp"
#include <iostream>
#include <string>
#include <vector>

void addWordsToFile() {
  std::string newWord{};
  std::cout << "Geben Sie das neue Wort ein: " << std::endl;
  std::cin >> newWord;

  std::vector<std::string> wordsList = readFile();
  wordsList.push_back(newWord);

  saveFile(wordsList);
}
