// 45. Jump Game II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {

        vector<int> jmp;

        for (int i = 0; i < nums.size(); i++) {
            jmp.push_back(0x7fffffff);
        }

        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            for (int j = 1; j <= v; j++) {
                if (i + j < jmp.size() && jmp[j + i] > i) {
                    jmp[j + i] = i;
                }
            }
        }

        // 

        int step = 0;
        int index = jmp[jmp.size() - 1];

        if (jmp.size() <= 1) {
            return 0;
        }

        while (index != 0) {
            index = jmp[index];
            step++;
        }

        return step + 1;
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
