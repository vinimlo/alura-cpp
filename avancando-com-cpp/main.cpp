#include "addWordsToFile.hpp"
#include "handleGuesses.hpp"
#include "letterExist.hpp"
#include "notHanged.hpp"
#include "printErrors.hpp"
#include "printHeader.hpp"
#include "printWordSpaces.hpp"
#include "readFile.hpp"
#include "saveFile.hpp"
#include "sortWords.hpp"
#include "wrongGuess.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

std::string secretWord;
std::map<char, bool> alreadyGuessed;
std::vector<char> wrongGuesses;

int main() {

  printHeader();
  sortWords();

  while (wrongGuess() && notHanged()) {
    printErrors();
    printWordSpaces();
    handleGuesses();
  }

  cout << endl;
  cout << "Ende des Spiel" << endl;
  cout << "das geheime Wort war: " << secretWord << endl;
  cout << endl;
  if (wrongGuess())
    cout << "Sorry, Sie haben verloren. :(" << endl;
  else {
    cout << "Glückwunsch! Sie haben gewonnen! :D" << endl;

    cout << "Möchten Sie ein neues Wort hinzufügen? (J/N): " << endl;
    char answer{};
    cin >> answer;

    if (answer == 'J' || answer == 'j')
      addWordsToFile();
  }

  return 0;
}
