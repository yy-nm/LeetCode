// 198. House Robber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];

        std::vector<int> getter(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                getter[i] = nums[i];
            }
            else if (i == 1) {
                getter[i] = std::max(nums[i], getter[i - 1]);
            }
            else if (i == 2) {
                getter[i] = std::max(nums[i] + getter[i - 2], getter[i - 1]);
            }
            else {
                getter[i] = std::max(nums[i] + std::max(getter[i - 2], getter[i - 3]), getter[i - 1]);
            }
        }

        return std::max(getter[getter.size() - 1], getter[getter.size() - 2]);
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
