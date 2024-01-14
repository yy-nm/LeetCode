// 76. Minimum Window Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length()) {
            return "";
        }

        vector<int> alphaBeta(256, 0);
        int alphaBetaCount = 0;

        for (const auto& it : t) {
            alphaBeta[it] ++;
            if (alphaBeta[it] == 1) {
                alphaBetaCount++;
            }
        }

        vector<int> indexes;
        for (int i = 0; i < s.length(); i++) {
            const auto& it = s[i];
            if (alphaBeta[it]) {
                indexes.push_back(i);
            }
        }

        int len_min = std::numeric_limits<int>::max();
        int start_index = 0;
        //int end_index = 0;
        int start_index_min = -1;
        vector<int> leftAlphaBeta(alphaBeta);
        int leftAlphaBetaCount = alphaBetaCount;

        for (int i = 0; i < indexes.size(); i++) {
            int index = indexes.at(i);
            const auto& it = s[index];

            leftAlphaBeta[it]--;
            if (!leftAlphaBeta[it]) {
                leftAlphaBetaCount--;
            }

            if (leftAlphaBetaCount) {
                continue;
            }

            for (start_index; start_index <= i; ) {

                int index2 = indexes.at(start_index);
                const auto& it = s[index2];

                if (index - index2 + 1 < len_min) {
                    len_min = index - index2 + 1;
                    start_index_min = index2;
                }

                start_index++;
                leftAlphaBeta[it]++;
                if (leftAlphaBeta[it] > 0) {
                    leftAlphaBetaCount++;
                    break;
                }
            }
        }

        if (start_index_min < 0) {
            return "";
        }

        return s.substr(start_index_min, len_min);
    }
};


int main()
{
    std::cout << "Hello World!\n";
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";

    std::cout << s.minWindow(s1, s2) << std::endl;
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
