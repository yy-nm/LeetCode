// 51. N-Queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

    inline int getSlashIndex(const int& x, const int& y, const int& n) {
        return y - x + n - 1;
    }

    inline int getBSlashIndex(const int& x, const int& y, const int& n) {
        return 2 * n - 2 - x - y;
    }

    void explore(int x, int y, vector<bool>& line, vector<bool>& column, vector<bool>& slash, vector<bool>& bslash, vector<string>& map, int q_count, const int& n, vector<vector<string>>& result) {

        if (y >= n) {
            y = 0;
            if (!line[x]) {
                return;
            }
            x++;
        }

        if (x >= n) {
            return;
        }

        if (map.size() <= x) {
            string s(n, '.');
            map.push_back(s);
        }

        if (map[x][y] == '.' && !line[x] && !column[y] && !slash[getSlashIndex(x, y, n)] && !bslash[getBSlashIndex(x, y, n)]) {
            //map[x][y] == 'Q';
            map.at(x).at(y) = 'Q';
            line[x] = true;
            column[y] = true;
            slash[getSlashIndex(x, y, n)] = true;
            bslash[getBSlashIndex(x, y, n)] = true;

            if (q_count + 1 == n) {
                result.push_back(map);

                map.at(x).at(y) = '.';
                line[x] = false;
                column[y] = false;
                slash[getSlashIndex(x, y, n)] = false;
                bslash[getBSlashIndex(x, y, n)] = false;
                return;
            }
            else {
                explore(x + 1, 0, line, column, slash, bslash, map, q_count + 1, n, result);
            }

            map.at(x).at(y) = '.';
            line[x] = false;
            column[y] = false;
            slash[getSlashIndex(x, y, n)] = false;
            bslash[getBSlashIndex(x, y, n)] = false;
        }

        explore(x, y + 1, line, column, slash, bslash, map, q_count, n, result);
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<bool> line(n, false);
        vector<bool> column(n, false);

        vector<bool> slash(n + n - 1, false);
        vector<bool> bslash(n + n - 1, false);

        vector<string> map;
        vector<vector<string>> result;

        string s(n, '.');
        map.push_back(s);

        //for (int i = 0; i < n; i++) {
        //    explore(0, i, line, column, slash, bslash, map, 0, n, result);
        //}
        explore(0, 0, line, column, slash, bslash, map, 0, n, result);

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
