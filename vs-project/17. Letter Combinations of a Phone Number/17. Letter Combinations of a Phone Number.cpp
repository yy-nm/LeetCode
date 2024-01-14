// 17. Letter Combinations of a Phone Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {

    const static unordered_map<int, vector<char>> kNums;
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.length() == 0) {
            return result;
        }

        vector<vector<char>> v;
        vector<int> count;
        for (int i = 0; i < digits.length(); i++) {
            v.push_back(kNums.at(digits[i] - '0'));
            count.push_back(0);
        }

        bool loop = true;

        bool add = false;
        while (loop) {
            string s;

            for (int i = 0; i < v.size(); i++) {
                if (add && i != 0) {
                    add = false;
                    count[i] ++;
                }
                if (count[i] >= v[i].size()) {
                    count[i] = 0;
                    add = true;

                    if (i == v.size() - 1) {
                        loop = false;
                        break;
                    }
                }
                s.push_back(v[i][count[i]]);
                if (i == 0) {
                    count[i] ++;
                }
            }
            if (loop)
                result.push_back(s);
        }


        return result;
    }
};

const unordered_map<int, vector<char>> Solution::kNums = {
    {2, {'a', 'b', 'c'}},
    {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}},
    {9, {'w', 'x', 'y', 'z'}},
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
