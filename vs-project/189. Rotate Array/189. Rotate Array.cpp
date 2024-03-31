// 189. Rotate Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (nums.size() == 1) {
            return;
        }

        if (k >= nums.size()) {
            k %= nums.size();
        }
        vector<int> shift;
        shift.reserve(k);

        for (int i = 0; i < k; i++) {
            shift.push_back(nums[nums.size() - k + i]);
        }

        for (int i = 0; i < nums.size() - k; i++) {
            nums[nums.size() - 1 - i] = nums[nums.size() - k - i - 1];
        }

        for (int i = 0; i < shift.size(); i++) {
            nums[i] = shift[i];
        }
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
