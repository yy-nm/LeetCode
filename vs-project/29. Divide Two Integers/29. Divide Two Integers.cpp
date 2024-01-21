// 29. Divide Two Integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {

        int64_t ddd = dividend;
        int64_t ds = divisor;

        int64_t count = 0;
        bool result_positive = true;
        if (ddd < 0) {
            result_positive ^= true;
            ddd = -ddd;
        }
        if (ds < 0) {
            result_positive ^= true;
            ds = -ds;
        }

        if (ds == 1) {
            count = ddd;
        }
        else if (ds == 2) {
            count = ddd >> 1;
        }
        else {

            while (ddd >= ds) {
                ddd -= ds;
                count++;
            }
        }

        if (!result_positive) {
            count = -count;
        }

        if (count > 0x7fffffff) {
            count = 0x7fffffff;
        }
        else if (count < (int)0x80000000) {
            count = (int)0x80000000;
        }

        return count;
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
