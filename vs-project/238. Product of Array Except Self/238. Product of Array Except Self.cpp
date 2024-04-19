// 238. Product of Array Except Self.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        int64_t v = 1;

        int index_0 = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (index_0 >= 0) {
                    return result;
                }
                index_0 = i;
            }
            else {
                v *= nums[i];
            }
        }

        if (index_0 >= 0) {
            result[index_0] = (int)v;
        }
        else {
            for (int i = 0; i < result.size(); i++) {
                result[i] = (int)(v / nums[i]);
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
