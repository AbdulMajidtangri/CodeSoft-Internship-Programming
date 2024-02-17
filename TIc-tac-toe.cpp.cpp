#include <iostream>
#include <iomanip>
#include<windows.h>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void displayBoard() {
    system("cls"); 
    cout << "\n\n\t\t\t\t\t\t\tTIC TAC TOE\n\n";
    cout << "\t\t\t\t\t\tPlayer 1 (X)  -  Player 2 (O)\n\n";
//    cout << "\t\t\t\t\t\t\t\t    |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "\t\t\t\t\t\t\t  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << "  |  ";
            }
        }
        cout << "\n\t\t\t\t\t\t\t";
        if (i < 2) {
            cout << "-----|-----|-----\n";
        }
    }
    cout << "\n";
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] != PLAYER_X && board[row][col] != PLAYER_O;
}

void makeMove(char player, int row, int col) {
    board[row][col] = player;
}

bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != PLAYER_X && board[i][j] != PLAYER_O) {
                return false;
            }
        }
    }
    return true;
}

char switchPlayer(char currentPlayer) {
    return currentPlayer == PLAYER_X ? PLAYER_O : PLAYER_X;
}

int main() {
	  system("color 71");

    char currentPlayer = PLAYER_X;

    while (true) {
        displayBoard();

        int move;
        cout << "\t\t\t\t" << currentPlayer << "'s turn (Enter a number 1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (!isValidMove(row, col)) {
            cout << "\tInvalid move. Try again." << endl;
            continue;
        }

        makeMove(currentPlayer, row, col);

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "\t" << currentPlayer << " wins!" << endl;
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "\tIt's a draw!" << endl;
            break;
        }

        currentPlayer = switchPlayer(currentPlayer);
    }

    char playAgain;
    cout << "\tPlay again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = (i * 3 + j) + '1'; 
            }
        }
        main();
    } else {
        cout << "\tGoodbye!" << endl;
    }

    return 0;
}

