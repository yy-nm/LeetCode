// 202. Happy Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>


static int numsSqure[] = {0, 1, 2 * 2, 3 * 3, 4 * 4, 5 * 5, 6 * 6, 7 * 7, 8 * 8, 9 * 9};

class Solution {

    int squre(int num) {
        int result = 0;

        int n;
        while (num > 0) {
            n = num % 10;
            result += numsSqure[n];
            num = num / 10;
        }

        return result;
    }

public:
    bool isHappy(int n) {
        std::unordered_set<int> has{n};

        do {
            n = squre(n);

            if (has.count(n))
                break;
            has.insert(n);

        } while (n != 1);


        return n == 1;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Solution s;

    std::cout << s.isHappy(2) << std::endl;
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
