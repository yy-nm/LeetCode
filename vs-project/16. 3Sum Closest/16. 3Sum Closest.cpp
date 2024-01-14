// 16. 3Sum Closest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



#define ABS(x) ((x) > 0 ? (x) : -(x))

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int64_t result = 0x7fffffff;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {

            int j = i + 1;
            int k = nums.size() - 1;

            //if (nums[i] > target) {
            //    break;
            //}

            if (i > 0 && (nums[i - 1] > target && nums[i - 1] > 0)) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while (j < k) {
                int v = nums[i] + nums[j] + nums[k];
                if (v == target) {

                    k--;
                    j++;

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    return target;
                }
                else if (v > target) {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
                else {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }

                if (ABS(target - v) < ABS(target - result)) {
                    result = v;
                }
            }
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
