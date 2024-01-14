// 81. Search in Rotated Sorted Array II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

    bool binary_search(vector<int>& nums, int target, int left, int right) {

        int middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }

public:
    bool search(vector<int>& nums, int target) {

        // find pivot index;
        int index_pivot = nums.size();

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                index_pivot = i;
                break;
            }
        }

        return binary_search(nums, target, 0, index_pivot - 1) || binary_search(nums, target, index_pivot, nums.size() - 1);
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
