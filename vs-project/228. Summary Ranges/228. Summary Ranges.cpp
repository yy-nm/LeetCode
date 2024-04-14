// 228. Summary Ranges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if (nums.size() == 0)
            return result;

        int left = nums[0];
        int index_left = 0;


        for (int i = 1; i < nums.size(); i++) {
            if (left != nums[i] - 1) {

                if (index_left == i - 1) {
                    result.push_back(std::to_string(nums[index_left]));
                }
                else {
                    result.push_back(std::to_string(nums[index_left]) + "->" + std::to_string(nums[i - 1]));
                }

                index_left = i;
            }

            left = nums[i];
        }

        if (index_left == nums.size() - 1) {
            result.push_back(std::to_string(nums[index_left]));
        }
        else {
            result.push_back(std::to_string(nums[index_left]) + "->" + std::to_string(nums[nums.size() - 1]));
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
