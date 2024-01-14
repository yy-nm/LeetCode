// 9. Palindrome Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        if (x < 10) {
            return true;
        }

        //int arrNumCount[10];
        int arrNum[11];
        int index = 0;
        int v;

        //memset(arrNumCount, 0, sizeof(arrNumCount));

        while (x > 0) {
            v = x % 10;
            arrNum[index++] = v;
            //arrNumCount[v] += 1;
            x /= 10;
        }

        //for (int i = 0; i < 10; i++) {
        //    if (arrNumCount[i] % 2 == 1)
        //        return false;
        //}

        for (int i = 0; i < index / 2; i++) {
            if (arrNum[i] != arrNum[index - i - 1])
                return false;
        }

        return true;
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
