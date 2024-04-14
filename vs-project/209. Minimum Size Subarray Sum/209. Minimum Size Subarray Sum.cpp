// 209. Minimum Size Subarray Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int total = 0;
        for (const auto& it : nums) {
            if (it >= target)
                return 1;

            total += it;
        }

        if (total < target)
            return 0;

        int length_max = nums.size() + 1;

        int left = -1;
        int right = -1;
        total = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (left == -1) {
                left = i;
                right = i;
                total = nums[i];
            }
            else {
                total += nums[i];

                if (total >= target) {
                    right = i;

                    if (right - left < length_max) {
                        length_max = right - left + 1;

                        if (length_max == 2)
                            return length_max;
                    }

                    while (total >= target) {
                        if (total - nums[left] >= target) {
                            total -= nums[left];

                            left++;

                            if (right - left < length_max) {
                                length_max = right - left + 1;

                                if (length_max == 2)
                                    return length_max;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }


        return length_max;
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
