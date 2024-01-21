// 26. Remove Duplicates from Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicated_count = 0;
        int swap_index = 2;
        int index = 1;
        while (index < nums.size()) {

            if (duplicated_count && index == swap_index) {
                if (swap_index + duplicated_count < nums.size()) {
                    int tmp = nums[swap_index];
                    nums[swap_index] = nums[swap_index + duplicated_count];
                    nums[swap_index + duplicated_count] = tmp;
                    swap_index++;
                }
                else {
                    break;
                }
            }

            if (nums[index] == nums[index - 1]) {

                if (swap_index + duplicated_count < nums.size()) {
                    int tmp = nums[index];
                    nums[index] = nums[swap_index + duplicated_count];
                    nums[swap_index + duplicated_count] = tmp;
                }
                else {
                    duplicated_count++;
                    break;
                }

                duplicated_count++;
                continue;
            }

            index++;
            if (duplicated_count == 0) {
                swap_index++;
            }
        }

        return nums.size() - duplicated_count;
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
