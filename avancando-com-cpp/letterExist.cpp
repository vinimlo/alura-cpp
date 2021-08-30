#include "letterExist.hpp"
#include <string>

extern std::string secretWord;

bool letterExist(char userGuess) {
  for (char letter : secretWord) {
    if (userGuess == letter)
      return true;
  }
  return false;
}
