// 34. Find First and Last Position of Element in Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 1 && nums[0] == target) {
            return { 0, 0 };
        }

        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        int pos = -1;
        while (left <= right) {

            middle = (left + right) / 2;
            if (target < nums[middle]) {
                right = middle - 1;
            }
            else if (target > nums[middle]) {
                left = middle + 1;
            }
            else {
                pos = middle;
                break;
            }
        }

        if (pos == -1) {
            return { -1, -1 };
        }

        int pos_l, pos_r;

        pos_l = pos;
        while (--pos_l >= 0) {
            if (nums[pos_l] != target) {
                break;
            }
        }

        pos_r = pos;
        while (++pos_r < nums.size()) {
            if (nums[pos_r] != target) {
                break;
            }
        }

        return { pos_l + 1, pos_r - 1 };
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
