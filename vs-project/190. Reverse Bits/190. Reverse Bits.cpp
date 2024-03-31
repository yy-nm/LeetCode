// 190. Reverse Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        //result |= (n & 0xff000000) >> 24;
        //result |= (n & 0x00ff0000) >> 8;

        //result |= (n & 0x0000ff00) << 8;
        //result |= (n & 0x000000ff) << 24;

        uint32_t v = 0x80000000;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                result |= v;
            }

            v >>= 1;
            n >>= 1;
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
