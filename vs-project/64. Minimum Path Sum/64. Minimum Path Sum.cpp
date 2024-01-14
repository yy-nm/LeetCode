// 64. Minimum Path Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    v.at(i).at(j) = grid.at(i).at(j);
                }
                else {
                    int min_value = std::numeric_limits<int>::max();
                    if (i > 0 && min_value > v.at(i - 1).at(j)) {
                        min_value = v.at(i - 1).at(j);
                    }
                    if (j > 0 && min_value > v.at(i).at(j - 1)) {
                        min_value = v.at(i).at(j - 1);
                    }

                    v.at(i).at(j) = min_value + grid.at(i).at(j);
                }
            }
        }

        return v.at(m - 1).at(n - 1);
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
