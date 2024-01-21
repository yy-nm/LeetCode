// 31. Next Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.size() <= 1) {
            return;
        }

        int index = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                index = i;
            }
        }

        // reverse
        if (index == -1) {
            int len = nums.size();
            for (int i = 0; i < len / 2; i++) {
                std::swap(nums[i], nums[len - 1 - i]);
            }
        }
        else {
            // find one just bigger one
            int v = nums[index];
            int bigger_index = index + 1;
            for (int i = index + 2; i < nums.size(); i++) {
                if (nums[i] > v && nums[i] < nums[bigger_index]) {
                    bigger_index = i;
                }
            }

            std::swap(nums[index], nums[bigger_index]);

            // sort index + 1 to end;
            std::sort(nums.begin() + index + 1, nums.end());
        }

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
