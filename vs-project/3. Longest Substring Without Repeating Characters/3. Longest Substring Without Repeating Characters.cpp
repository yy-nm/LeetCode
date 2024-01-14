// 3. Longest Substring Without Repeating Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index_start = 0;
        int index = 0;
        int max_len = 0;
        int i;

        std::bitset<256> conflict;
        conflict.reset();

        while (index < s.length()) {
            const auto& v = s[index];
            if (conflict[v]) {
                // forward find same value
                for (i = index - 1; i >= 0; i--) {
                    if (s[i] == v) {
                        break;
                    }
                }

                index_start = i + 1;
                conflict.reset();

                for (i = index_start; i <= index; i++) {
                    conflict[s[i]] = true;
                }
            }
            else {
                conflict[v] = true;

                if (index + 1 - index_start > max_len) {
                    max_len = index + 1 - index_start;
                }
            }

            index++;
        }

        return max_len;
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
