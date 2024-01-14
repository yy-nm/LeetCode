// 8. String to Integer (atoi).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {

        bool bPositive = true;
        int64_t result = 0;
        int index = 0;
        int v;
        bool bHasSignedFlag = false;

        while (index < s.length()) {
            v = s[index];
            if (v >= '0' && v <= '9') {
                break;
            }
            if (v == '-' || v == '+') {
                if (v == '-')
                    bPositive = false;
                if (bHasSignedFlag) {
                    return result;
                }

                bHasSignedFlag = true;
            }
            else if (!bHasSignedFlag && (v == ' ' || v == '\n' || v == '\t' || v == '\v')) {

            }
            else {
                return result;
            }

            index++;
        }

        for (int i = index; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                result = result * 10 + s[i] - '0';
                if (result > 0x7fffffff) {
                    break;
                }
            }
            else {
                break;
            }
        }

        if (bPositive && result >= 0x7fffffff) {
            result = 0x7fffffff;
        }
        else if (!bPositive && result >= 0x80000000) {
            result = 0x7fffffff * -1 - 1;
        }
        else if (!bPositive) {
            result *= -1;
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
