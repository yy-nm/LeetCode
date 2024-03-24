// 151. Reverse Words in a String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        string result;
        result.reserve(s.size());

        int index = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && index >= 0) {
                if (result.size() > 0) {
                    result.push_back(' ');
                }
                result.append(s.substr(i + 1, index - i));

                index = -1;
            }
            else if (s[i] != ' ' && index == -1) {
                index = i;
            }
        }

        if (index >= 0) {
            if (result.size() > 0) {
                result.push_back(' ');
            }
            result.append(s.substr(0, index + 1));
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
