// 65. Valid Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

    // ÅÐ¶ÏÊýÖµ
    bool CheckNum(string s, bool bWithDot) {

        if (s.length() == 0)
            return false;

        if (!bWithDot) {
            for (const auto& it : s) {
                if (it == '.')
                    return false;
            }
        }

        bool bHasSign = false;
        bool bHasNum = false;
        bool bHasDot = false;

        for (const auto& it : s) {
            if (it >= '0' && it <= '9') {
                bHasNum = true;
            }
            else if (it == '-' || it == '+') {
                if (bHasSign) {
                    return false;
                }
                bHasSign = true;

                if (bHasDot || bHasNum) {
                    return false;
                }
            }
            else if (it == '.') {
                if (bHasDot) {
                    return false;
                }

                bHasDot = true;
            }
            else {
                return false;
            }
        }

        if (!bHasNum) {
            return false;
        }

        return true;
    }

public:
    bool isNumber(string s) {

        vector<bool> ValidCharacter(256, false);
        for (int i = 0; i <= 9; i++) {
            ValidCharacter.at('0' + i) = true;
        }

        ValidCharacter.at('E') = true;
        ValidCharacter.at('e') = true;
        ValidCharacter.at('-') = true;
        ValidCharacter.at('+') = true;
        ValidCharacter.at('.') = true;

        int iDotCount = 0;
        int iECount = 0;

        for (const auto& it : s) {
            if (!ValidCharacter.at(it)) {
                return false;
            }

            if (it == '.')
                iDotCount++;
            if (it == 'e' || it == 'E') {
                iECount++;
            }
        }

        if (iDotCount > 1 || iECount > 1) {
            return false;
        }


        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E' || s[i] == 'e') {
                bool bRet = CheckNum(s.substr(index, i), true);
                index = i + 1;

                if (!bRet) return false;
            }
        }

        return CheckNum(s.substr(index), index == 0);
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
