// 53. Maximum Subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = 0;
        int index = -1;
        int sum = 0;
        bool got = false;

        for (int i = 0; i < nums.size(); i++) {
            const auto& v = nums[i];
            if (index < 0 && v < 0) {
                continue;
            }
            else if (index < 0) {
                index = i;
                sum = v;
                if (sum > max) {
                    max = sum;
                    got = true;
                }
            }
            else {
                if (v + sum < 0) {
                    index = -1;
                }
                else {
                    sum += v;
                    if (sum > max) {
                        max = sum;
                        got = true;
                    }
                }
            }
        }

        if (!got) {
            // get the max one as result;
            max = 0x8fffffff;
            for (const auto& it : nums) {
                if (it > max) {
                    max = it;
                }
            }
        }

        return max;
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
