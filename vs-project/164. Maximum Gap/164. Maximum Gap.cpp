// 164. Maximum Gap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

    void couting_sort(std::vector<int>& nums, int base)
    {
        std::vector<int> k(10, 0);
        std::vector<int> b(nums.size(), 0);

        for (const auto& it : nums) {
            k[(it / base) % 10] ++;
        }

        for (int i = 1; i < k.size(); i++) {
            k[i] += k[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            int key = (nums[i] / base) % 10;
            b[k[key] - 1] = nums[i];
            k[key] --;
        }

        nums = b;
    }

    void radix_sort(std::vector<int>& nums)
    {
        int max_value = 0;

        for (const auto& it : nums) {
            if (it > max_value)
                max_value = it;
        }

        int base = 1;
        for (int i = 0; i < 10; i++) {
            if (base > max_value)
                break;
            couting_sort(nums, base);
            base *= 10;
        }
    }

public:
    int maximumGap(vector<int>& nums) {
        int gap = 0;
        radix_sort(nums);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > gap)
                gap = nums[i] - nums[i - 1];
        }

        return gap;
    }
};


int main()
{
    std::cout << "Hello World!\n";

    vector<int> v = { 3,60,9,1, 5 };
    Solution s;

    std::cout << s.maximumGap(v) << std::endl;

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
