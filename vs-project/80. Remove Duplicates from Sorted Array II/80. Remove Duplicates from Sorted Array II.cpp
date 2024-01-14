// 80. Remove Duplicates from Sorted Array II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int index_write = 1;
        int index_read = 1;
        int v = nums[0];
        int count = 1;

        while (index_read < nums.size()) {

            if (nums[index_read] == v) {
                if (count < 2) {
                    nums[index_write++] = v;
                    count++;
                }
            }
            else {
                count = 1;
                v = nums[index_read];
                nums[index_write++] = v;
            }

            index_read++;
        }

        return index_write;
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
