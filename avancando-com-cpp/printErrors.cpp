#include "printErrors.hpp"
#include <iostream>
#include <vector>

extern std::vector<char> wrongGuesses;

void printErrors() {
  std::cout << std::endl;
  std::cout << "Falsche Vermutungen: ";
  for (char letter : wrongGuesses)
    std::cout << letter << " ";
  std::cout << std::endl;
}
