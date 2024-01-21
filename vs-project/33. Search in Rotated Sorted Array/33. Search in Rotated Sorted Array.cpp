// 33. Search in Rotated Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        bool meet_rotate = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
            else {
                if (i > 0) {
                    if (target > nums[i - 1] && target < nums[i]) {
                        return -1;
                    }
                    if (nums[i] < nums[i - 1]) {
                        meet_rotate = true;

                        if (target > nums[i - 1]) {
                            return -1;
                        }
                        else if (target < nums[i]) {
                            return -1;
                        }
                    }
                }

                if (meet_rotate && target < nums[i]) {
                    return -1;
                }
            }
        }

        return -1;
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
