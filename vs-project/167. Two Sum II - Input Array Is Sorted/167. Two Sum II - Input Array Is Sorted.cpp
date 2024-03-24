// 167. Two Sum II - Input Array Is Sorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> range(2001, -1);

        for (int i = 0; i < numbers.size(); i++) {
            range[numbers[i] + 1000] = i;
        }

        int v;
        vector<int> result;

        for (int i = 0; i < numbers.size(); i++) {
            v = target + 1000 - numbers[i];
            if (v >= range.size() || v < 0 || range[v] == -1) {
                continue;
            }

            if (range[v] == i) {
                if (i > 0 && numbers[i - 1] == numbers[i]) {
                    result.push_back(i);
                    result.push_back(i + 1);
                    break;
                }
                else if (i < numbers.size() && numbers[i + 1] == numbers[i]) {
                    result.push_back(i + 1);
                    result.push_back(i + 2);
                    break;
                }
            }
            else {
                result.push_back(i + 1);
                result.push_back(range[v] + 1);
                break;
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
