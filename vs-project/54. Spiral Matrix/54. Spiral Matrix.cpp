// 54. Spiral Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;
        result.reserve(matrix.size());

        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }

        int line = matrix.size();
        int column = matrix[0].size();

        for (int i = 0; i < (line + 1) / 2; i++) {

            if (i > column - 1 - i)
                break;

            // horizontal - 1
            for (int j = i; j <= column - 1 - i; j++) {
                result.push_back(matrix[i][j]);
            }
            // vertical - 1
            for (int j = i + 1; j <= line - 1 - i; j++) {
                result.push_back(matrix[j][column - 1 - i]);
            }

            // horizontal - 2
            if (i + 1 <= line - 1 - i) {
                for (int j = column - 1 - (i + 1); j >= i; j--) {
                    result.push_back(matrix[line - 1 - i][j]);
                }
            }

            // vertical - 2
            if (i < column - 1 && i < column - 1 - i) {
                for (int j = line - 1 - (i + 1); j >= i + 1; j--) {
                    result.push_back(matrix[j][i]);
                }
            }
        }

        return result;
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
