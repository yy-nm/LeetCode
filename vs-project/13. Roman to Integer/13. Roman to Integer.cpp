// 13. Roman to Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
    const static unordered_map<int, int> sValue;

public:
    int romanToInt(string s) {

        int result = 0;
        int pre = 0;

        for (int i = 0; i < s.length(); i++) {
            int pre = s[i];

            if (i + 1 < s.length()) {
                int v = s[i + 1];

                if (pre == 'C' && (v == 'D' || v == 'M')) {
                    result -= 100;
                    i++;
                    pre = v;
                }
                else if (pre == 'X' && (v == 'L' || v == 'C')) {
                    result -= 10;
                    i++;
                    pre = v;
                }
                else if (pre == 'I' && (v == 'V' || v == 'X')) {
                    result -= 1;
                    i++;
                    pre = v;
                }
                result += sValue.at(pre);
            }
            else {
                result += sValue.at(pre);
            }
        }

        return result;
    }
};

const unordered_map<int, int> Solution::sValue = {
    {'I', 1 },
    {'V', 5 },
    {'X', 10 },
    {'L', 50 },
    {'C', 100 },
    {'D', 500 },
    {'M', 1000 },
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
