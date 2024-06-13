// Assumption: User input for row and column is valid (1-3).
// No error handling for invalid input is implemented for simplicity.

#include <stdio.h>

int tic_tac_toe(int n, char matrix[][3]);
void visual(int n, char matrix[][3]);
int winner(int n, char matrix[][3]);

int main() {
    int n = 3;
    char matrix[n][n]; // matrix: 2D array representing the tic-tac-toe game board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = ' '; //
        }
    }

    int result = tic_tac_toe(n, matrix);
    if (result) {
        printf("\n   #################################\n\n");
        printf("Player %d won! Congratulations!!\n", result);
        visual(n, matrix);
    } else {
        printf("\n   #################################\n\n");
        printf("It was a tough competition!! You can play again.\n");
        visual(n, matrix);
    }
    return 0;
}

// Function to play the game of tic-tac-toe
int tic_tac_toe(int n, char matrix[n][n]) {
    for (int i = 0; i < 9; i++) {
        int row, col, player;
        player = (i % 2) + 1; // There are two players: 1 & 2

        visual(n, matrix);
        printf("Player %d (%c) Turn. Enter Row and Column: ", player, (player == 1) ? 'x' : 'o');
        scanf("%d %d", &row, &col);

        // Keep Track of both players move on the game board
        if (player == 1)
            matrix[row - 1][col - 1] = 'x';
        else
            matrix[row - 1][col - 1] = 'o';

        // Check for a winner only after both players have made at least 5 moves,
        // as it's impossible to win before this point
        if (i > 3) {
            int result = winner(n, matrix);
            if (result)
                return result;
        }
    }
    return 0;
}

// Function to display the current state of the game board
void visual(int n, char matrix[n][n]) {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("        %c   |    %c    |   %c\n", matrix[i][0], matrix[i][1], matrix[i][2]);
        if (i < 2)
            printf("     _________________________\n");
    }
}

// Function to determine the winner of the game
int winner(int n, char matrix[n][n]) {
    char winner = ' ';

    // Check diagonals for a win
    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
        winner = matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
        winner = matrix[0][2];

    // Check rows and columns for a win
    for (int i = 0; i < n; i++) {
        // Check rows
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != ' '){
            winner = matrix[i][0];
            break;
        }
        // Check columns
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != ' '){
            winner = matrix[0][i];
            break;
        }
    }

    // If winner is found, return the corresponding player number
    if(winner == 'x')
        return 1;
    else if(winner == 'o')
        return 2;

    // If no winner found, return 0;
    return 0;
}
