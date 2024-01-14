// 73. Set Matrix Zeroes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> line;
        vector<int> column;
        line.resize(matrix.size(), 0);
        column.resize(matrix.at(0).size(), 0);

        for (int i = 0; i < matrix.size(); i++) {
            const auto& v = matrix.at(i);
            for (int j = 0; j < v.size(); j++) {
                if (v.at(j) == 0) {
                    line.at(i) = 1;
                    column.at(j) = 1;
                }
            }
        }

        for (int i = 0; i < line.size(); i++) {
            const auto& it = line.at(i);
            if (!it) continue;
            auto& v = matrix.at(i);
            v.clear();
            v.resize(column.size(), 0);
        }

        for (int j = 0; j < column.size(); j++) {
            const auto& it = column.at(j);
            if (!it) continue;
            for (int i = 0; i < line.size(); i++) {
                matrix.at(i).at(j) = 0;
            }
        }
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
