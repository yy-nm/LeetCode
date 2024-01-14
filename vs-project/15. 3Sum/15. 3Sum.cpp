// 15. 3Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {

            if (i == 0 || nums[i - 1] != nums[i]) {

                int low = i + 1, high = nums.size() - 1, sum = -nums[i];

                while (low < high) {
                    if (nums[low] + nums[high] == sum) {

                        ans.push_back({ nums[i], nums[low], nums[high] });

                        while (low < high && nums[low] == nums[low + 1])
                            low++;

                        while (low < high && nums[high] == nums[high - 1])
                            high--;
                        low++;
                        high--;
                    }

                    else if (nums[low] + nums[high] < sum) {
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }
        return ans;
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
