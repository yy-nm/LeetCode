// 91. Decode Ways.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {

        if (s[0] == 0) {
            return 0;
        }

        int v = -1;
        for (const auto& it : s) {
            if (it == v && v == '0') {
                return 0;
            }

            v = it;
        }

        vector<int> dp(s.length(), 0);

        //int v;
        int v_in_ten;
        for (int i = 0; i < s.length(); i++) {
            v = s[i] - '0';
            if (i == 0) {
                if (v > 0 && v <= 26) {
                    dp[i] = 1;
                }
                else {
                    return 0;
                }
            }
            else {
                v_in_ten = (s[i - 1] - '0') * 10;
                if (v > 0 && v_in_ten != 0 && v + v_in_ten <= 26) {
                    //dp[i] = dp[i - 1] + 1;
                    if (i > 1) {
                        dp[i] = dp[i - 1] + dp[i - 2];
                    }
                    else {
                        dp[i] = dp[i - 1] + 1;
                    }
                }
                else if (v == 0 && v_in_ten > 20) {
                    return 0;
                }
                else if (v == 0 && v_in_ten <= 20) {
                    // 
                    if (i > 1) {
                        dp[i] = dp[i - 2];
                    }
                    else {
                        dp[i] = dp[i - 1];
                    }
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
        }

        return dp[s.length() - 1];
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
