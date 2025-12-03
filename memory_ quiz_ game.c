#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int score = 0;
int lives = 3;
int highScore = 0;

void loadHighScore() {
    FILE *f = fopen("memory_highscore.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", &highScore);
        fclose(f);
    } else {
        highScore = 0;
    }
}

void saveHighScore() {
    if (score > highScore) {
        FILE *f = fopen("memory_highscore.txt", "w");
        if (f != NULL) {
            fprintf(f, "%d", score);
            fclose(f);
        }
    }
}

void showSequence(int seq[], int length) {
    system("cls");
    printf("Memorize this sequence:\n\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", seq[i]);
        Sleep(500);
    }
    Sleep(1000);
    system("cls");
}

int playRound(int round) {
    int seq[20];
    int input[20];

    // generate random sequence
    for (int i = 0; i < round; i++) {
        seq[i] = (rand() % 9) + 1;
    }

    showSequence(seq, round);

    printf("Enter the sequence:\n");
    for (int i = 0; i < round; i++) {
        scanf("%d", &input[i]);
    }

    // check correctness
    for (int i = 0; i < round; i++) {
        if (seq[i] != input[i]) {
            printf("\nWrong sequence!\n");
            lives--;
            return 0;
        }
    }

    printf("\nCorrect!\n");
    score++;
    return 1;
}

void help() {
    system("cls");
    printf("=== Help ===\n\n");
    printf("This is a memory quiz game.\n");
    printf("A sequence of numbers will appear on screen.\n");
    printf("You must type the same sequence correctly.\n");
    printf("Each round the sequence gets longer.\n");
    printf("You have 3 lives. Wrong input reduces lives.\n");
    printf("Score increases for each correct round.\n\n");
    printf("Press any key to return...");
    getch();
}

void rules() {
    system("cls");
    printf("=== Rules ===\n\n");
    printf("1. You start with 3 lives.\n");
    printf("2. A random sequence of numbers will be shown.\n");
    printf("3. You must type the same sequence.\n");
    printf("4. Wrong input reduces lives.\n");
    printf("5. Score increases for each correct round.\n");
    printf("6. High score is saved automatically.\n\n");
    printf("Press any key to return...");
    getch();
}

void playGame() {
    int round = 1;
    score = 0;
    lives = 3;

    while (lives > 0) {
        printf("\nRound %d\n", round);
        if (!playRound(round)) {
            Beep(300, 200);
        } else {
            Beep(900, 100);
        }
        round++;
        Sleep(1000);
    }

    saveHighScore();
    system("cls");
    printf("\nGame Over!\n");
    printf("Your Score: %d\n", score);
    printf("High Score: %d\n", highScore);
    Beep(200, 400);
    printf("\nPress any key to return to menu...");
    getch();
}

int main() {
    srand(time(NULL));
    loadHighScore();

menuStart:
    system("cls");
    printf("=== MEMORY QUIZ GAME ===\n\n");
    printf("1. Start Game\n");
    printf("2. Help\n");
    printf("3. Rules\n");
    printf("4. Exit\n\n");
    printf("Enter choice: ");

    char choice = getch();

    if (choice == '1') {
        playGame();
        goto menuStart;
    } else if (choice == '2') {
        help();
        goto menuStart;
    } else if (choice == '3') {
        rules();
        goto menuStart;
    } else if (choice == '4') {
        return 0;
    } else {
        goto menuStart;
    }
}
