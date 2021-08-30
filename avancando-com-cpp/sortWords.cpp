#include "readFile.hpp"
#include "sortWords.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

extern std::string secretWord;

void sortWords() {
  std::vector<std::string> wordsList = readFile();

  srand(time(NULL));
  int randomIndex = rand() % wordsList.size();

  secretWord = wordsList[randomIndex];
}
