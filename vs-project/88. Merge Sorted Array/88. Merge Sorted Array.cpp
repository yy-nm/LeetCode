// 88. Merge Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_write = m + n - 1;


        while (m > 0 || n > 0) {
            if (m > 0 && n > 0) {
                if (nums1[m - 1] > nums2[n - 1]) {
                    nums1[index_write--] = nums1[--m];
                }
                else {
                    nums1[index_write--] = nums2[--n];
                }
            }
            else if (n > 0) {
                nums1[index_write--] = nums2[--n];
            }
            else {
                break;
            }
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";

    vector<int> v1{ 1,2,3,0,0,0 };
    vector<int> v2{ 2,5,6 };
    Solution s;
    s.merge(v1, 3, v2, 3);

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
