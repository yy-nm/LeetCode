// 47. Permutations II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


class Solution {

    void generate(const vector<int>& nums, vector<int>& middle, vector<bool>& mark, vector<vector<int>>& result) {

        for (int i = 0; i < nums.size(); i++) {
            if (mark[i]) continue;

            mark[i] = true;
            middle.push_back(nums[i]);
            if (middle.size() == nums.size()) {
                result.push_back(middle);
            }
            else {
                generate(nums, middle, mark, result);
            }
            mark[i] = false;
            middle.pop_back();
        }

        if (nums.size() == middle.size()) {
            result.push_back(middle);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> result;
        vector<bool> mark;

        mark.resize(nums.size(), false);
        vector<int> middle;
        for (int i = 0; i < nums.size(); i++) {

            //if (i == 0 || nums[i - 1] != nums[i]) 
            {
                mark[i] = true;
                middle.push_back(nums[i]);
                generate(nums, middle, mark, result);
                mark[i] = false;
                middle.clear();
            }

        }

        set<vector<int>> s;
        for (const auto& it : result) {
            s.insert(it);
        }

        result.clear();
        for (const auto& it : s) {
            result.push_back(it);
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
