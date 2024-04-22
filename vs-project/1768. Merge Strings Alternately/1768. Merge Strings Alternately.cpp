// 1768. Merge Strings Alternately.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length = std::max(word1.length(), word2.length());
        std::string result;
        for (int i = 0; i < length; i++) {
            if (i >= word1.length()) {
                result.append(word2.substr(i));
                break;
            }
            else if (i >= word2.length()) {
                result.append(word1.substr(i));
                break;
            }
            else {
                result.push_back(word1[i]);
                result.push_back(word2[i]);
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
