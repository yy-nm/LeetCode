// 32. Longest Valid Parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> mark;
        vector<int> left_index;


        for (int i = 0; i < s.length(); i++) {
            mark.push_back(false);
            char c = s[i];
            if (c == ')') {
                if (left_index.size() > 0) {
                    int index = left_index.back();
                    left_index.pop_back();
                    mark[index] = mark[i] = true;
                }
            }
            else if (c == '(') {
                left_index.push_back(i);
            }
        }

        int continue_true_count = 0;
        int continue_true_count_max = 0;

        for (const auto& it : mark) {
            if (it) {
                continue_true_count++;
            }
            else {
                if (continue_true_count > continue_true_count_max) {
                    continue_true_count_max = continue_true_count;
                }
                continue_true_count = 0;
            }
        }

        if (continue_true_count > continue_true_count_max) {
            continue_true_count_max = continue_true_count;
        }

        return continue_true_count_max;
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
