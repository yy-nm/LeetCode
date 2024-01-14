// 89. Gray Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {

        bitset<16> b;
        vector<int> result;
        result.push_back(0);

        for (int i = 0; i < n; i++) {
            b.set(i, true);
            result.push_back(b.to_ulong());
        }

        for (int i = 0; i < n - 1; i++) {
            b.set(i, false);
            result.push_back(b.to_ulong());
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
