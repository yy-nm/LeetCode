// 38. Count and Say.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {

public:
    string countAndSay(int n) {

        if (n == 1) {
            return "1";
        }
        else {
            string s = countAndSay(n - 1);
            string result;

            char c;
            int count = 0;

            for (int i = 0; i < s.length(); i++) {
                if (i == 0) {
                    c = s[i];
                    count = 1;
                }
                else {
                    if (c == s[i]) {
                        count++;
                    }
                    else {
                        result.push_back('0' + count);
                        result.push_back(c);
                        c = s[i];
                        count = 1;
                    }
                }
            }

            result.push_back('0' + count);
            result.push_back(c);
            return result;
        }
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
