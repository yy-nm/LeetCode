// 219. Contains Duplicate II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if (k <= 0)
            return false;
        if (k == 1) {
            int first = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == first)
                    return true;
                first = nums[i];
            }

            return false;
        }
        k++;
        unordered_set<int> distinct;

        for (int i = 0; i < k && i < nums.size(); i++) {
            distinct.insert(nums[i]);
            if (distinct.size() != i + 1)
                return true;
        }

        for (int i = k; i < nums.size(); i++) {
            distinct.erase(nums[i - k]);
            distinct.insert(nums[i]);
            if (distinct.size() != k)
                return true;
        }

        return false;
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
