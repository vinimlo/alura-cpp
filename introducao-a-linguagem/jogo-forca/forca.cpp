#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

std::string secretWord{"WASSERMELONE"};
map<char, bool> alreadyGuessed;
std::vector<char> wrongGuesses;

std::vector<string> readFile();

void sortWords();
void printHeader();
void printErrors();
void printWordSpaces();
void handleGuesses();
void addWordsToFile();
void saveFile(std::vector<string> wordsList);

bool letterExist(char userGuess);
bool wrongGuess();
bool notHanged();

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

void sortWords() {
  std::vector<string> wordsList = readFile();

  srand(time(NULL));
  int randomIndex = rand() % wordsList.size();

  secretWord = wordsList[randomIndex];
}

std::vector<string> readFile() {
  ifstream wordsFile;
  wordsFile.open("worter.txt");

  if (wordsFile.is_open()) {
    int numberOfWords{};
    wordsFile >> numberOfWords;

    std::vector<string> wordsOfFile;

    for (int i = 0; i < numberOfWords; ++i) {
      string wordRead;
      wordsFile >> wordRead;
      wordsOfFile.push_back(wordRead);
    }

    wordsFile.close();
    return wordsOfFile;
  } else {
    cout << endl;
    cout << "Die Words-Datei konnte nicht erreicht werden." << endl;
    exit(0);
  }
}

void printHeader() {
  cout << "***********************************" << endl;
  cout << "*** Willkommen beim Henkerspiel ***" << endl;
  cout << "***********************************" << endl;
}

void printErrors() {
  cout << endl;
  cout << "Falsche Vermutungen: ";
  for (char letter : wrongGuesses)
    cout << letter << " ";
  cout << endl;
}

void printWordSpaces() {
  for (char letter : secretWord) {
    if (alreadyGuessed[letter])
      cout << letter << " ";
    else
      cout << "_ ";
  }
  cout << endl;
}

void handleGuesses() {
  char userGuess{};
  cout << "Ihre Vermutung: ";
  cin >> userGuess;
  userGuess = toupper(userGuess);

  alreadyGuessed[userGuess] = true;

  if (letterExist(userGuess))
    cout << "Sie haben es richtig gemacht!" << endl;
  else {
    cout << "Sorry, nicht richtig." << endl;
    wrongGuesses.push_back(userGuess);
  }
}

void addWordsToFile() {
  string newWord{};
  cout << "Geben Sie das neue Wort ein: " << endl;
  cin >> newWord;

  std::vector<string> wordsList = readFile();
  wordsList.push_back(newWord);

  saveFile(wordsList);
}

void saveFile(std::vector<string> wordsList) {
  ofstream wordsFile;
  wordsFile.open("worter.txt");

  if (wordsFile.is_open()) {
    wordsFile << wordsList.size() << endl;

    for (string word : wordsList) {
      wordsFile << word << endl;
    }

    wordsFile.close();
  } else {
    cout << "Die Words-Datei konnte nicht erreicht werden." << endl;
    exit(0);
  }
}

bool letterExist(char userGuess) {
  for (char letter : secretWord) {
    if (userGuess == letter)
      return true;
  }
  return false;
}

bool wrongGuess() {
  for (char letter : secretWord)
    if (!alreadyGuessed[letter])
      return true;
  return false;
}

bool notHanged() { return wrongGuesses.size() < 6; }
