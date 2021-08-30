#include "handleGuesses.hpp"
#include "letterExist.hpp"
#include <iostream>
#include <map>
#include <vector>

extern std::map<char, bool> alreadyGuessed;
extern std::vector<char> wrongGuesses;

void handleGuesses() {
  char userGuess{};
  std::cout << "Ihre Vermutung: ";
  std::cin >> userGuess;
  userGuess = toupper(userGuess);

  alreadyGuessed[userGuess] = true;

  if (letterExist(userGuess))
    std::cout << "Sie haben es richtig gemacht!" << std::endl;
  else {
    std::cout << "Sorry, nicht richtig." << std::endl;
    wrongGuesses.push_back(userGuess);
  }
}
