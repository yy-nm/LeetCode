// 59. Spiral Matrix II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;

        if (n <= 0) {
            return result;
        }

        for (int i = 0; i < n; i++) {
            vector<int> v;
            v.resize(n, 0);
            result.push_back(v);
        }

        int num = 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            // line 1
            for (int j = i; j < n - 1 - i; j++) {
                result.at(i).at(j) = num++;
            }

            // column 1
            for (int j = i; j < n - 1 - i; j++) {
                result.at(j).at(n - 1 - i) = num++;
            }

            // line 2
            for (int j = n - 1 - i; j > i; j--) {
                result.at(n - 1 - i).at(j) = num++;
            }

            // column 2
            for (int j = n - 1 - i; j > i; j--) {
                result.at(j).at(i) = num++;
            }
        }

        // 
        if (n % 2 == 1) {
            result.at(n / 2).at(n / 2) = num;
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
