#include "saveFile.hpp"
#include <fstream>
#include <iostream>

void saveFile(std::vector<std::string> wordsList) {
  std::ofstream wordsFile;
  wordsFile.open("worter.txt");

  if (wordsFile.is_open()) {
    wordsFile << wordsList.size() << std::endl;

    for (std::string word : wordsList) {
      wordsFile << word << std::endl;
    }

    wordsFile.close();
  } else {
    std::cout << "Die Words-Datei konnte nicht erreicht werden." << std::endl;
    exit(0);
  }
}
