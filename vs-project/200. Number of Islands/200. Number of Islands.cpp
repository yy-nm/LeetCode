// 200. Number of Islands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

    //void visitIsland(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
    void visitIsland(vector<vector<char>>& grid, int i, int j) {
        //if (visited[i][j]) {
        //    return;
        //}
        //visited[i][j] = true;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';

        if (i > 0) {
            //visitIsland(grid, visited, i - 1, j);
            visitIsland(grid, i - 1, j);
        }
        if (i < grid.size() - 1) {
            //visitIsland(grid, visited, i + 1, j);
            visitIsland(grid, i + 1, j);
        }

        if (j > 0) {
            //visitIsland(grid, visited, i, j - 1);
            visitIsland(grid, i, j - 1);
        }
        if (j < grid[i].size() - 1) {
            //visitIsland(grid, visited, i, j + 1);
            visitIsland(grid, i, j + 1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        //vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                //if (!visited[i][j]) {
                    if (grid[i][j] == '1') {
                        //visitIsland(grid, visited, i, j);
                        visitIsland(grid, i, j);
                        count++;
                    }
                //}

            }
        }

        return count;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Solution s;
    vector<vector<char>> grid = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };

    std::cout << s.numIslands(grid) << std::endl;
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
