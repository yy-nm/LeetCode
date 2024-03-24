// 154. Find Minimum in Rotated Sorted Array II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        int m;

        while (left < right) {
            m = (left + right) / 2;

            if (nums[m] == nums[left] && nums[m] == nums[right]) {
                //left = m + 1;
                left++;
                right--;
            }
            else if (nums[m] >= nums[left] && nums[m] > nums[right]) {
                left = m + 1;
            }
            else if (nums[m] > nums[left] && nums[m] == nums[right]) {
                right = m - 1;
            }
            else if (nums[m] >= nums[left] && nums[m] <= nums[right]) {
                right = m - 1;
            }
            else if (nums[m] <= nums[left] && nums[m] < nums[right]) {
                right = m;
            }
            else if (nums[m] < nums[left] && nums[m] == nums[right]) {
                right = m;
            }
            else {
                if (left == m) {
                    if (nums[m] < nums[right])
                        return nums[m];
                    else {
                        return nums[right];
                    }
                    break;
                }
            }
        }

        return nums[left];
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
