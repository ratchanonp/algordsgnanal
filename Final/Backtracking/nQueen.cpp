#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int>> &board);

bool isRowSafe(vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }
    return true;
}

bool isColSafe(vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }
    return true;
}

bool isDiagonalSafe(vector<vector<int>> &board, int row, int col)
{
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (auto dir : directions)
    {
        int i = row;
        int j = col;
        while (i >= 0 && i < board.size() && j >= 0 && j < board.size())
        {
            if (board[i][j] == 1)
                return false;
            i += dir.first;
            j += dir.second;
        }
    }

    return true;
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    return isRowSafe(board, row, col) && isColSafe(board, row, col) && isDiagonalSafe(board, row, col);
}
void solve(vector<vector<int>> board, int col)
{
    // Copy the board
    vector<vector<int>> temp = board;

    // Base Case
    if (col == board.size())
    {
        printBoard(board);
        return;
    }

    // Recursive Case
    for (int row = 0; row < board.size(); row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            solve(board, col + 1);
        }
        board = temp;
    }
}

void printBoard(vector<vector<int>> &board)
{
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    int row = 0;
    int col = 0;

    solve(board, col);
}