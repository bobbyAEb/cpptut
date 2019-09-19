#include <cstdlib>
#include <iostream>
/*In this exercise you will write a small \guessing" game. The program will pick a random number
from 0 to 99 and you will be guessing this number by providing your guess through stdin. Depending on
which number you have guessed there are 3 outcomes:
• You have guessed the number. Then the program has to tell you that you have won.
• Your number if larger than the target one. The program should tell you that it’s number is smaller.
• Your number is smaller than the target one. The program should tell you that its number is larger.
The game goes on until you have guessed the number.*/
int main() {
  int random = std::rand() % 100;
  bool is_correct = false;
  int guess;
  while (!is_correct) {
    std::cin >> guess;
    if (guess > random) {
      std::cout << "Guess is larger than the random" << std::endl;
    } else if (guess < random) {
      /* code */
      std::cout << "Guess is smaller than the random" << std::endl;

    } else {
      std::cout << "Guess is right" << std::endl;
      is_correct = true;
    }
  }
  return 0;
}