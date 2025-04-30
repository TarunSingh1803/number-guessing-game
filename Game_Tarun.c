#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void displayBlock(int block[4][4], char blockName) {
    printf("\nBlock_%c 2D Array:\n", blockName);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", block[i][j]);
        }
        printf("\n");
    }
}

int getValidResponse() {
    char response[10];
    while (1) {
        printf("Answer (YES/NO): ");
        scanf("%9s", response);
        
        // Convert to uppercase for comparison
        for(int i = 0; response[i]; i++) {
            response[i] = toupper(response[i]);
        }
        
        if (strcmp(response, "YES") == 0) return 1;
        if (strcmp(response, "NO") == 0) return 0;
        
        printf("Invalid input! Please enter 'YES' or 'NO'\n");
        while (getchar() != '\n'); // Clear input buffer
    }
}

int playGame() {
    int Block_A[4][4] = {{8, 9, 10, 11}, {15, 14, 13, 12}, {24, 25, 26, 27}, {28, 29, 30, 31}};
    int Block_B[4][4] = {{16, 27, 31, 20}, {17, 21, 26, 30}, {18, 22, 29, 25}, {19, 28, 24, 23}};
    int Block_C[4][4] = {{1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23}, {31, 29, 27, 25}};
    int Block_D[4][4] = {{2, 3, 6, 7}, {10, 11, 14, 15}, {30, 31, 27, 26}, {18, 19, 22, 23}};
    int Block_E[4][4] = {{4, 5, 6, 7}, {12, 20, 28, 31}, {29, 13, 21, 15}, {22, 23, 14, 30}};
    int sum = 0;

    printf("\nThink of a number between 0 and 31\n");
    printf("Look at each block and answer if your number is present in it.\n");

    displayBlock(Block_A, 'A');
    if (getValidResponse()) sum += Block_A[0][0];

    displayBlock(Block_B, 'B');
    if (getValidResponse()) sum += Block_B[0][0];

    displayBlock(Block_C, 'C');
    if (getValidResponse()) sum += Block_C[0][0];

    displayBlock(Block_D, 'D');
    if (getValidResponse()) sum += Block_D[0][0];

    displayBlock(Block_E, 'E');
    if (getValidResponse()) sum += Block_E[0][0];

    printf("\nYour number is: %d\n", sum);
    return sum;
}

int main() {
    char playAgain[10];
    
    do {
        system("cls"); // Clear screen (use "clear" for Unix-based systems)
        playGame();
        
        printf("\nWould you like to play again? (YES/NO): ");
        scanf("%9s", playAgain);
        
        // Convert to uppercase
        for(int i = 0; playAgain[i]; i++) {
            playAgain[i] = toupper(playAgain[i]);
        }
        
    } while (strcmp(playAgain, "YES") == 0);
    
    printf("\nThank you for playing!\n");
    return 0;
}
