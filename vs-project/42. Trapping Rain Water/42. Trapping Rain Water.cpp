// 42. Trapping Rain Water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

    int calc(const vector<int>& height, int start, int end) {
        int m = 0;

        if (end - start <= 1) {
            return m;
        }

        int h = height[start];
        if (h > height[end]) {
            h = height[end];
        }


        for (int i = start + 1; i < end; i++) {
            m += h - height[i];
        }

        return m;
    }
public:
    int trap(vector<int>& height) {

        int left_index = 0;
        int left_v = 0;
        bool loop = true;
        int i = 0;

        left_v = height[left_index];
        for (i = left_index + 1; i < height.size(); i++) {
            int v = height[i];
            if (v >= left_v) {
                left_v = v;
                left_index = i;
            }
            else {
                break;
            }
        }

        int result = 0;

        while (loop) {

            int right_index = left_index;
            int right_v = 0;

            for (i = right_index + 1; i < height.size(); i++) {
                int v = height[i];
                if (v >= left_v) {
                    right_v = v;
                    right_index = i;
                    break;
                }
                else {
                    if (v > right_v) {
                        right_v = v;
                        right_index = i;
                    }
                }
            }

            // break condition
            if (left_index + 1 >= height.size())
                break;

            result += calc(height, left_index, right_index);

            left_index = right_index;
            left_v = right_v;
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
