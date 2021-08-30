#include "wrongGuess.hpp"
#include <map>
#include <string>

extern std::string secretWord;
extern std::map<char, bool> alreadyGuessed;

bool wrongGuess() {
  for (char letter : secretWord)
    if (!alreadyGuessed[letter])
      return true;
  return false;
}
