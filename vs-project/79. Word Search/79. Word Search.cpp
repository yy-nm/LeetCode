// 79. Word Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <tuple>

using namespace std;


class Solution {

    bool check(vector<vector<char>>& board, const string &word,const int &index, vector<vector<bool>> &mark, stack<tuple<int, int>> &s, const int &line, const int &column) {

        const auto& pos = s.top();
        s.pop();

        int x = std::get<0>(pos);
        int y = std::get<1>(pos);

        if (!mark[x][y]) {

            if (index == word.size())
                return true;

            mark[x][y] = true;
            if (x - 1 >= 0) {
                const auto& c = board[x - 1][y];
                if (word[index] == c) {

                    s.push(make_tuple(x - 1, y));
                    auto bOK = check(board, word, index + 1, mark, s, line, column);
                    if (bOK)
                        return true;
                }
            }
            if (x + 1 < line) {
                const auto& c = board[x + 1][y];
                if (word[index] == c) {

                    s.push(make_tuple(x + 1, y));
                    auto bOK = check(board, word, index + 1, mark, s, line, column);
                    if (bOK)
                        return true;
                }
            }

            if (y - 1 >= 0) {
                const auto& c = board[x][y - 1];
                if (word[index] == c) {
                    s.push(make_tuple(x, y - 1));
                    auto bOK = check(board, word, index + 1, mark, s, line, column);
                    if (bOK)
                        return true;
                }
            }
            if (y + 1 < column) {
                const auto& c = board[x][y + 1];
                if (word[index] == c) {

                    s.push(make_tuple(x, y + 1));
                    auto bOK = check(board, word, index + 1, mark, s, line, column);
                    if (bOK)
                        return true;
                }
            }

            mark[x][y] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> alphaBeta(256, 0);

        vector<vector<bool>> mark;

        for (const auto& b : board) {
            for (const auto& it : b) {
                alphaBeta[it]++;
            }
            mark.push_back(vector<bool>(b.size(), false));
        }

        vector<int> leftAlphaBeta(alphaBeta);
        for (const auto& it : word) {
            leftAlphaBeta[it] --;

            if (leftAlphaBeta[it] < 0) {
                return false;
            }
        }

        leftAlphaBeta.clear();
        leftAlphaBeta.resize(256, 0);
        int leftAlphaBetaCount = 0;
        for (const auto& it : word) {
            leftAlphaBeta[it] ++;
            if (leftAlphaBeta[it] == 1) {
                leftAlphaBetaCount++;
            }
        }

        if (word.length() == 1) {
            return true;
        }

        stack<tuple<int, int>> s;

        for (int i = 0; i < board.size(); i++) {
            const auto& b = board.at(i);
            for (int j = 0; j < b.size(); j++) {
                const auto& it = b.at(j);

                if (word[0] == it) {

                    //mark[i][j] = true;
                    s.push(make_tuple(i, j));
                    bool bOk = check(board, word, 1, mark, s, board.size(), b.size());
                    if (bOk)
                        return true;
                }
            }
        }

        return false;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    Solution s;
    //vector<vector<char>> board{ {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
    vector<vector<char>> board{ {'a','a','b','a','a','b'},{'a','a','b','b','b','a'},{'a','a','a','a','b','a'},{'b','a','b','b','a','b'},{'a','b','b','a','b','a'},{'b','a','a','a','a','b'} };
    //string word = "ABCCED";
    string word = "bbbaabbbbbab";

    std::cout << s.exist(board, word) << std::endl;
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
