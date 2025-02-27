#include <iostream>
#include <vector>
#include <string>
using namespace std;
void displayBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    char currentPlayer = 'X';
    vector<vector<char>> board(3, vector<char>(3, ' '));
    bool gameWon = false;
    bool draw = false;

    do {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[row][col] = currentPlayer;
        gameWon = checkWin(board, currentPlayer);
        draw = checkDraw(board);
        switchPlayer(currentPlayer);
    } while (!gameWon && !draw);
    displayBoard(board);
    if (gameWon)
    {
        if(currentPlayer=='X')
            cout << "Player O wins!\n";
        else
            cout << "Player X wins!\n";
    }
    else
        cout << "It's a draw!\n";

    return 0;
}
void displayBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}
void switchPlayer(char& currentPlayer) {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}
