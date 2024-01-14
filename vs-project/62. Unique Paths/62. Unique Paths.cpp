// 62. Unique Paths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {

    int generateMap(int i, int j) {

        if (i <= 1 || j <= 1) {
            return 1;
        }

        if (map[i][j] != 0) {
            return map[i][j];
        }

        map[i][j] = generateMap(i - 1, j) + generateMap(i, j - 1);
        return map[i][j];
    }

    static int map[101][101];

public:
    int uniquePaths(int m, int n) {
        return generateMap(m, n);
    }
};

int Solution::map[101][101] = { 0 };

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
