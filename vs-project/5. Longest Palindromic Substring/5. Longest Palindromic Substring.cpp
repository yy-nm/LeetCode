// 5. Longest Palindromic Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


#define MIN(x, y) ((x) < (y) ? (x) : (y))

class Solution {
public:
    string longestPalindrome(string s) {
        string result;

        if (s.length() < 0) {
            return result;
        }

        result = s.substr(0, 1);

        // single number worlds count
        for (int i = 1; i < s.length(); i++) {

            int j = 1;
            int len = MIN(s.length() - i - 1, i);
            while (len > 0) {
                if (s[i + j] != s[i - j]) {
                    break;
                }

                len--;
                j++;
            }

            j--;
            if (j > 0 && 2 * j + 1 > result.length()) {
                result = s.substr(i - j, 2 * j + 1);
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {

            if (s[i] != s[i + 1]) {
                continue;
            }

            int j = 1;
            int len = MIN(s.length() - i - 1 - 1, i);
            while (len > 0) {
                if (s[i + 1 + j] != s[i - j]) {
                    break;
                }

                len--;
                j++;
            }

            j--;
            if (2 * j + 2 > result.length()) {
                result = s.substr(i - j, 2 * j + 2);
            }
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
