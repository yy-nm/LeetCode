// 44. Wildcard Matching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {

        stack<int> indexes;

        indexes.push(0);

        if (s.length() > 0 && p.length() > 0) {
            if (s[s.length() - 1] != p[p.length() - 1] && p[p.length() - 1] != '*' && p[p.length() - 1] != '?')
                return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char ch_s = s[i];

            if (indexes.empty()) {
                return false;
            }

            unordered_set<int> tmp;

            while (!indexes.empty()) {
                int index = indexes.top();
                indexes.pop();

                if (index >= p.length()) {
                    continue;
                }

                char ch_p = p[index];

                if (ch_p == '*') {
                    while (index + 1 < p.length() && p[index + 1] == '*') {
                        index++;
                    }
                    tmp.insert(index);

                    if (index + 1 < p.length() && (p[index + 1] == ch_s || p[index + 1] == '?')) {
                        tmp.insert(index + 2);
                    }
                    if (index + 1 < p.length() && i + 1 < s.length() && (p[index + 1] == s[i + 1] || p[index + 1] == '?')) {
                        tmp.insert(index + 1);
                    }
                    if (index + 1 >= p.length()) {
                        tmp.insert(index + 1);
                    }
                }
                else if (ch_p == '?' || ch_p == ch_s) {
                    tmp.insert(index + 1);
                }
            }

            for (const auto& it : tmp) {
                indexes.push(it);
            }
            tmp.clear();
        }

        if (indexes.empty()) {
            return false;
        }

        int len_p = p.length();

        int max_index = 0;

        while (!indexes.empty()) {
            int index = indexes.top();
            indexes.pop();

            if (index >= len_p) {
                return true;
            }

            if (index > max_index) {
                max_index = index;
            }
        }

        while (max_index < p.length() && p[max_index] == '*') { max_index++; }

        return max_index >= len_p;
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
