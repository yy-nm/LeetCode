// 43. Multiply Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1.length() == 0 || num2.length() == 0) {
            return "0";
        }

        string result = "";

        string target = num1;
        string multiply = num2;
        if (target.length() < num2.length()) {
            target = num2;
            multiply = num1;
        }

        int carry = 0;
        string middle;
        for (int i = 0; i < multiply.length(); i++) {
            int v = multiply[multiply.length() - 1 - i] - '0';
            if (v == 0) {
                continue;
            }
            middle.clear();
            for (int j = 0; j < i; j++) {
                middle.push_back('0');
            }

            carry = 0;
            for (int j = 0; j < target.length(); j++) {
                int target_v = target[target.length() - 1 - j] - '0';

                int after = v * target_v + carry;

                carry = after / 10;
                middle.push_back('0' + (after % 10));
            }
            if (carry > 0) {
                middle.push_back('0' + carry);
            }

            // add to result;

            carry = 0;
            if (result.length() == 0) {
                result = middle;
            }
            else {
                for (int j = 0; j < middle.length(); j++) {
                    if (j >= result.length()) {
                        int after = middle[j] - '0' + carry;
                        carry = after / 10;
                        result.push_back((after % 10) + '0');
                    }
                    else {
                        int after = middle[j] - '0' + result[j] - '0' + carry;
                        carry = after / 10;
                        result[j] = ((after % 10) + '0');
                    }
                }

                if (carry > 0) {
                    if (middle.length() >= result.length()) {
                        result.push_back(carry + '0');
                    }
                    else {
                        int j = middle.length();
                        while (carry > 0) {
                            if (j < result.length()) {
                                int after = result[j] - '0' + carry;
                                carry = after / 10;
                                result[j] = '0' + (after % 10);
                            }
                            else {
                                int after = result[j] - '0' + carry;
                                carry = after / 10;
                                result.push_back('0' + (after % 10));
                            }
                            j++;
                        }
                    }
                }
            }
        }


        if (result.length() == 0) {
            result = "0";
        }

        for (int i = 0; i < result.length() / 2; i++) {
            int tmp = result[i];
            result[i] = result[result.length() - 1 - i];
            result[result.length() - 1 - i] = tmp;
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
