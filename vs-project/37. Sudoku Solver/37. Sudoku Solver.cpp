// 37. Sudoku Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {


    bool fillWords(vector<vector<char>>& board, int line, int column) {

        if (line >= 8 && column >= 9) {
            return true;
        }

        if (column >= 9) {
            column = 0;
            line += 1;
        }

        if (board[line][column] != '.') {
            return fillWords(board, line, column + 1);
        }
        else {
            bool value_list[10] = { false, false, false, false, false, false, false, false, false, false, };

            // line 
            for (int i = 0; i < 9; i++) {
                if (board[line][i] != '.') {
                    value_list[board[line][i] - '0'] = true;
                    //if (value_list[board[line][i] - '0']) {
                    //    //return false;
                    //}
                    //else {
                    //    value_list[board[line][i] - '0'] = true;
                    //}
                }
            }

            // column
            for (int i = 0; i < 9; i++) {
                if (board[i][column] != '.') {
                    value_list[board[i][column] - '0'] = true;
                    //if (value_list[board[i][column] - '0']) {
                    //    //return false;
                    //}
                    //else {
                    //    value_list[board[i][column] - '0'] = true;
                    //}
                }
            }

            // block
            int line_base = (line / 3) * 3;
            int column_base = (column / 3) * 3;
            for (int i = 0; i < 3; i++) {
                if (i + line_base == line)
                    continue;

                for (int j = 0; j < 3; j++) {

                    if (column_base + j == column)
                        continue;

                    if (board[i + line_base][column_base + j] == '.')
                        continue;

                    value_list[board[i + line_base][column_base + j] - '0'] = true;

                    //if (value_list[board[i + line_base][column_base + j] - '0']) {
                    //    //return false;
                    //}
                    //else {
                    //    value_list[board[i + line_base][column_base + j] - '0'] = true;
                    //}
                }
            }

            for (int i = 1; i <= 9; i++) {
                if (!value_list[i]) {
                    board[line][column] = '0' + i;
                    if (fillWords(board, line, column + 1)) {
                        return true;
                    }
                }
            }
        }

        board[line][column] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        fillWords(board, 0, 0);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
