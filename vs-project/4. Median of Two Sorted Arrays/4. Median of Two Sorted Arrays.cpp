// 4. Median of Two Sorted Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t total_length = nums1.size() + nums2.size();
        size_t middle_index1 = total_length / 2;
        size_t middle_index2 = total_length / 2;
        size_t index1 = 0;
        size_t index2 = 0;
        size_t total_index = 0;
        int v1, v2, v;
        double result = 0;

        if (total_length % 2 == 0) {
            middle_index2 = middle_index1 - 1;
        }

        while (index1 < nums1.size() || index2 < nums2.size()) {
            v1 = v2 = INT_MAX;

            if (index1 < nums1.size()) {
                v1 = nums1[index1];
            }

            if (index2 < nums2.size()) {
                v2 = nums2[index2];
            }

            if (v1 < v2) {
                index1++;
                v = v1;
            }
            else {
                index2++;
                v = v2;
            }

            if (total_index == middle_index2 || total_index == middle_index1) {
                result += v;
            }

            total_index++;

            if (total_index > middle_index1) {
                break;
            }
        }

        if (middle_index1 != middle_index2) {
            result /= 2;
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
