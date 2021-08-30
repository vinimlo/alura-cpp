#include "readFile.hpp"
#include <fstream>
#include <iostream>

std::vector<std::string> readFile() {
  std::ifstream wordsFile;
  wordsFile.open("worter.txt");

  if (wordsFile.is_open()) {
    int numberOfWords{};
    wordsFile >> numberOfWords;

    std::vector<std::string> wordsOfFile;

    for (int i = 0; i < numberOfWords; ++i) {
      std::string wordRead;
      wordsFile >> wordRead;
      wordsOfFile.push_back(wordRead);
    }

    wordsFile.close();
    return wordsOfFile;
  } else {
    std::cout << std::endl;
    std::cout << "Die Words-Datei konnte nicht erreicht werden." << std::endl;
    exit(0);
  }
}
