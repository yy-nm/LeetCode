// 70. Climbing Stairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {

    static int kStairs[46];

    int generate(int n) {

        if (n <= 1)
            return 1;

        if (kStairs[n] == 0) {
            kStairs[n] = generate(n - 1) + generate(n - 2);
        }

        return kStairs[n];
    }

public:
    int climbStairs(int n) {
        int result = generate(n);


        return result;
    }
};

int Solution::kStairs[46] = { 1, 1 };

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
