// 36. Valid Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        bool mem[9];

        // line
        for (int i = 0; i < 9; i++) {
            const auto& b = board[i];

            memset(mem, 0, sizeof(bool) * 9);
            for (int j = 0; j < 9; j++) {
                const auto& ch = b[j];

                if (ch == '.')
                    continue;

                if (mem[ch - '1']) {
                    return false;
                }
                else {
                    mem[ch - '1'] = true;
                }
            }
        }

        // column
        for (int i = 0; i < 9; i++) {
            memset(mem, 0, sizeof(bool) * 9);
            for (int j = 0; j < 9; j++) {
                const auto& ch = board[j][i];

                if (ch == '.')
                    continue;

                if (mem[ch - '1']) {
                    return false;
                }
                else {
                    mem[ch - '1'] = true;
                }
            }
        }

        // block
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                int line = i * 3;
                int column = j * 3;
                memset(mem, 0, sizeof(bool) * 9);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        const auto& ch = board[line + k][column + l];

                        if (ch == '.')
                            continue;

                        if (mem[ch - '1']) {
                            return false;
                        }
                        else {
                            mem[ch - '1'] = true;
                        }
                    }
                }

            }
        }


        return true;
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
