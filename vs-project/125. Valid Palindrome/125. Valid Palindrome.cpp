// 125. Valid Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        
        string t;
        t.reserve(s.length() + 1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                t.push_back(s[i] - 'A' + 'a');
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                t.push_back(s[i]);
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                t.push_back(s[i]);
            }
        }

        int len = t.length();
        for (int i = 0; i < t.length() / 2; i++) {
            if (t[i] != t[len - 1 - i])
                return false;
        }

        return true;
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
