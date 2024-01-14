// 6. Zigzag Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<int> vKeyIndexs;

        int index = numRows - 1;
        while (index < s.length()) {
            vKeyIndexs.push_back(index);
            index += 2 * (numRows - 1);
        }
        vKeyIndexs.push_back(index);


        std::string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < vKeyIndexs.size(); j++) {
                int keyIndex = vKeyIndexs[j];

                if ((i > 0 || j == 0) && i != numRows - 1) {
                    index = keyIndex - (numRows - 1) + i;
                    if (index < s.length())
                        result.push_back(s[index]);
                }

                index = keyIndex + numRows - 1 - i;
                if (index < s.length())
                    result.push_back(s[index]);
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
