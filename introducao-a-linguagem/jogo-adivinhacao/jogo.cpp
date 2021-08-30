#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  srand(time(NULL));
  const int SECRETNUMBER {rand()%100};
  int guess {};
  bool rightGuess {};
  bool greaterGuess {};
  bool wrongGuess {true};
  int roundNumber{0};

  double points {1000};
  double lostPoints {0};

  char level {};

  int guessLimit {};

  cout << "***********************\n";
  cout << "* Jogo da adivinhação *\n";
  cout << "***********************\n";

  cout << "Escolha seu nível de dificuldade\n";
  cout << "Fácil (F), Médio (M), Difícil (D)\n";

  cin >> level;

  if (level == 'F') guessLimit = 15;
  else if (level == 'M') guessLimit = 10;
  else guessLimit = 5;

  while (wrongGuess && guessLimit){
    roundNumber++;
    cout << "Tentativa " << roundNumber << endl;
    cout << "Qual seu chute? ";
    cin >> guess;
    rightGuess = guess == SECRETNUMBER;
    greaterGuess = guess > SECRETNUMBER;

    if (rightGuess) {
      cout << "Parabéns, você acertou o número!\n";
      wrongGuess = false;
    }
    else if (greaterGuess) cout << "Seu chute foi maior que o número secreto.\n";
    else cout << "Seu chute foi menor que o número secreto.\n";
    lostPoints += abs(SECRETNUMBER - guess)/2.0;
    guessLimit--;
  }
  if (wrongGuess) cout << "Você perdeu.. :(\n";
  else {
    cout << "Você finalizou o jogo com " << roundNumber << " tentativas e ";
    cout.precision(2);
    cout << fixed;
    cout << points - lostPoints << " pontos!\n";
  }
  return 0;
}
