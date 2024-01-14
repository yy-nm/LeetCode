// 97. Interleaving String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        vector<vector<int> > dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0)
                    continue;
                int value = 0;
                if (i > 0) {
                    if (s3[dp.at(i - 1).at(j)] == s1[i - 1] && value < dp.at(i - 1).at(j) + 1) {
                        value = dp.at(i - 1).at(j) + 1;
                    }
                }

                if (j > 0) {
                    if (s3[dp.at(i).at(j - 1)] == s2[j - 1] && value < dp.at(i).at(j - 1) + 1) {
                        value = dp.at(i).at(j - 1) + 1;
                    }
                }

                dp.at(i).at(j) = value;
            }
        }

        return dp.at(s1.length()).at(s2.length()) == s3.length();
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
