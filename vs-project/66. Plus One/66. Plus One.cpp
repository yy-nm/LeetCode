// 66. Plus One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        bool bGoToNext = true;

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (bGoToNext) {
                bGoToNext = false;
                digits[i] += 1;
            }

            if (digits[i] >= 10) {
                digits[i] -= 10;
                bGoToNext = true;
            }
            else {
                break;
            }
        }

        if (bGoToNext) {
            digits.insert(digits.begin(), 1);
        }


        return digits;
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
