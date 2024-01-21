// 41. First Missing Positive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min_value = 0x7fffffff;
        int max_value = 0;
        int n = nums.size();
        int count = 0; // postive count

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if (v <= 0)
                continue;

            count++;
            if (v < min_value) {
                min_value = v;
            }
            if (v > max_value) {
                max_value = v;
            }
        }

        if (min_value > 1) {
            return 1;
        }

        vector<bool> mark;
        mark.resize((count <= max_value ? count : max_value) + 1);

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if (v <= 0)
                continue;

            if (v >= mark.size())
                continue;

            mark[v] = true;
        }

        for (int i = 1; i < mark.size(); i++) {
            if (!mark[i]) {
                return i;
            }
        }

        return mark.size();
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
