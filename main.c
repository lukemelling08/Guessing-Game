#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int genNum(const int min, const int max) {
    return rand() % (max - min + 1) + min;
}

int guess(void) {
    int guess;
    printf("Guess a number: \n");
    scanf("%d", &guess);
    return guess;
}

bool isRight(const int guess, const int real, const int remainingLives) {
    if (guess == real) return true;
    printf("%d is incorrect! %i remaining lives\n", guess, remainingLives);
    if (remainingLives == 0) printf("You lose!");
    return false;
}

int main(void) {
    srand(time(NULL)); // generate a seed
    const int number = genNum(1, 100);
    int guessedNum;
    int lives = 10;
    do {
        guessedNum = guess();
        if (guessedNum > number) {printf("guess lower\n");} else if (guessedNum != number) {printf("guess higher\n");}
        lives--;
    } while (!isRight(guessedNum, number, lives) && lives > 0);
    if (isRight(guessedNum, number, lives)) printf("number %d is correct!\n", number);
    return 0;
}