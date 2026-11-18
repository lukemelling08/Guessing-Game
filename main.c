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

bool isRight(const int guess, const int real) {
    return guess == real;
}

int main(void) {
    srand(time(NULL)); // generate a seed
    const int number = genNum(1, 100);
    int guessedNum;
    int lives = 10;
    do {
        guessedNum = guess();
        if (!isRight(guessedNum, number)) {
            printf("%d is incorrect! %i remaining lives\n", guessedNum, lives-1);
            if (guessedNum > number) {printf("guess lower\n");} else {printf("guess higher\n");}
        }
        lives--;
    } while (!isRight(guessedNum, number) && lives > 0);
    if (lives < 1 && !isRight(guessedNum, number)) {
        printf("You lose!");
    } else {
        printf("number %d is correct!\n", number);
    }
    return 0;
}