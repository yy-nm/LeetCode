// 96. Unique Binary Search Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

    static vector<int> s_cacheResult;

    int generate(int n) {

        if (s_cacheResult.at(n) != 0) {
            return s_cacheResult.at(n);
        }
        else {
            if (n <= 1) {
                s_cacheResult.at(n) = 1;
                return s_cacheResult.at(n);
            }
            else {
                int v = 0;
                for (int i = 0; i < n; i++) {
                    v += generate(i) * generate(n - i - 1);
                }
                s_cacheResult.at(n) = v;
                return s_cacheResult.at(n);
            }
        }
    }

public:
    int numTrees(int n) {

        return generate(n);
    }
};

vector<int> Solution::s_cacheResult(20, 0);


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
