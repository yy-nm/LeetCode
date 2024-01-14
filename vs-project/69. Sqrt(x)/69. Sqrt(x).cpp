// 69. Sqrt(x).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {

public:
    int mySqrt(int x) {

        if (x == 0) {
            return x;
        }

        int result = 0;

        int left = 1;
        int right = x;
        while (left < right) {
            int64_t middle = ((int64_t)left + (int64_t)right) / 2;
            int multiple = x / middle;
            if (multiple == middle) {
                return middle;
            }
            else if (multiple < middle) {
                right = middle - 1;
            }
            else if (multiple > middle) {

                if (left == middle) {
                    for (int i = left; i <= right; i++) {
                        int m = x / i;
                        if (m == i) return i;
                        else if (m < i) return i - 1;
                    }
                    return right;
                }

                left = middle;
            }
        }

        return left;
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
