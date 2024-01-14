// 12. Integer to Roman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        int v;
        string result;

        if (num >= 1000) {
            v = num / 1000;
            while (v-- > 0) {
                result.push_back('M');
            }

            num %= 1000;
        }

        if (num >= 100) {

            v = num / 100;
            if (v == 9) {
                result.push_back('C');
                result.push_back('M');
            }
            else if (v >= 5) {
                result.push_back('D');
                while (v-- - 5 > 0) {
                    result.push_back('C');
                }
            }
            else if (v == 4) {
                result.push_back('C');
                result.push_back('D');
            }
            else {
                while (v-- > 0) {
                    result.push_back('C');
                }
            }

            num %= 100;
        }

        if (num >= 10) {
            v = num / 10;
            if (v == 9) {
                result.push_back('X');
                result.push_back('C');
            }
            else if (v >= 5) {
                result.push_back('L');
                while (v-- - 5 > 0) {
                    result.push_back('X');
                }
            }
            else if (v == 4) {
                result.push_back('X');
                result.push_back('L');
            }
            else {
                while (v-- > 0) {
                    result.push_back('X');
                }
            }

            num %= 10;
        }

        v = num;

        if (v == 9) {
            result.push_back('I');
            result.push_back('X');
        }
        else if (v >= 5) {
            result.push_back('V');
            while (v-- - 5 > 0) {
                result.push_back('I');
            }
        }
        else if (v == 4) {
            result.push_back('I');
            result.push_back('V');
        }
        else {
            while (v-- > 0) {
                result.push_back('I');
            }
        }

        num %= 10;

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
