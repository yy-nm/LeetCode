// 67. Add Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string result;

        string reverse_a(a.rbegin(), a.rend());
        string reverse_b(b.rbegin(), b.rend());

        int len_a = a.length();
        int len_b = b.length();

        int len = len_a > len_b ? len_a : len_b;
        result.reserve(len + 1);

        bool bGotoNext = false;
        for (int i = 0; i < len; i++) {
            if (i < len_b && i < len_a) {
                if (reverse_a[i] == reverse_b[i]) {

                    result.append(1, bGotoNext ? '1' : '0');
                    bGotoNext = false;
                    if (reverse_a[i] == '1') {
                        bGotoNext = true;
                    }
                }
                else {
                    result.append(1, bGotoNext ? '0' : '1');
                }
            }
            else if (i < len_b) {
                if (reverse_b[i] == '1') {
                    result.append(1, bGotoNext ? '0' : '1');
                }
                else {
                    result.append(1, bGotoNext ? '1' : '0');
                    bGotoNext = false;
                }
            }
            else if (i < len_a) {
                if (reverse_a[i] == '1') {
                    result.append(1, bGotoNext ? '0' : '1');
                }
                else {
                    result.append(1, bGotoNext ? '1' : '0');
                    bGotoNext = false;
                }
            }
        }

        if (bGotoNext) {
            result.append(1, '1');
        }

        return string(result.rbegin(), result.rend());
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
