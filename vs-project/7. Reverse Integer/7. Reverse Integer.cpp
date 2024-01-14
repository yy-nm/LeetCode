// 7. Reverse Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        std::vector<int> part;

        bool bPostive = (x >= 0);
        if (!bPostive) {
            if (x == 0x80000000)
                return 0;
            x *= -1;
        }

        while (x > 0) {
            part.push_back(x % 10);

            x /= 10;
        }

        int64_t result = 0;
        int len = part.size();
        for (int i = 0; i < len; i++) {
            //result = result * 10 + part[len - i - 1];
            result = result * 10 + part[i];
        }

        if (((uint64_t)result) > 0xffffffff) {
            return 0;
        }

        if (((uint64_t)result) > 0x7fffffff) {
            return 0;
        }


        if (!bPostive) {
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
