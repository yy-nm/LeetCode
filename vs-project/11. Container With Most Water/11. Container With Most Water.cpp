// 11. Container With Most Water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y) )

class Solution {
public:
    int maxArea(vector<int>& height) {

        int max = 0;
        int value = 0;
        int left = 0;
        int right = (int)height.size() - 1;

        while (left < right) {
            value = MIN(height[left], height[right]) * (right - left);
            if (value > max) {
                max = value;
            }

            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }

        return max;
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
