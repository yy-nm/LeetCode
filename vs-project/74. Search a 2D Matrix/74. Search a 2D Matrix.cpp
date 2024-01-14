// 74. Search a 2D Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lineIndex = 0;
        int left = -1;
        int right = -1;

        while (lineIndex < matrix.size()) {

            const auto& line = matrix.at(lineIndex);

            if (left < 0 && right < 0) {
                left = 0;
                right = matrix[lineIndex].size() - 1;
            }
            else {
                left = 0;
            }

            //if (left == right) {
            //    if (line.at(left) == target)
            //        return true;
            //}
            bool bIsSame = false;
            while (left <= right) {
                int middle = (left + right) / 2;
                const auto& v = line.at(middle);
                if (v > target) {
                    right = middle;
                }
                else if (v < target) {
                    left = middle + 1;
                }
                else {
                    return true;
                }

                if (bIsSame && left == right) {
                    break;
                }
                else  if (left == right) {
                    bIsSame = true;
                }
            }

            lineIndex++;
        }


        return false;
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
