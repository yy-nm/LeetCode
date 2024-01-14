// 90. Subsets II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {

    void generate(vector<vector<int>>& result, vector<int>& v, int index, int k, const vector<int>& nums) {
        if (v.size() == k) {
            result.push_back(v);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i == index || nums[i] != nums[i - 1]) {
                v.push_back(nums.at(i));
                generate(result, v, i + 1, k, nums);
                v.pop_back();
            }
        }
    }

public:

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        result.push_back(vector<int>());

        for (int i = 1; i <= nums.size(); i++) {
            vector<int> v;
            generate(result, v, 0, i, nums);
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
