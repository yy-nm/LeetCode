// 22. Generate Parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    void generate(int left_count, int target_count, string str, vector<string>& result)
    {
        if (left_count == 0) {
            if (str.length() < target_count * 2) {
                for (size_t i = str.length(); i < target_count * 2; i++) {
                    str.push_back(')');
                }

            }

            result.push_back(str);
        }
        else {
            generate(left_count - 1, target_count, str + '(', result);
            if (str.length() < (target_count - left_count) * 2) {
                generate(left_count, target_count, str + ')', result);
            }
        }
    }
public:
    vector<string> generateParenthesis(int target) {
        vector<string> result;

        if (target <= 0) {
            result;
        }

        string s = "(";
        generate(target - 1, target, s, result);
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
