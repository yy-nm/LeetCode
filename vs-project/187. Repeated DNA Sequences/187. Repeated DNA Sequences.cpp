// 187. Repeated DNA Sequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {


public:
    vector<string> findRepeatedDnaSequences(string s) {
        unsigned int alphaBeta[26];
        alphaBeta['A' - 'A'] = 0b00;
        alphaBeta['C' - 'A'] = 0b01;
        alphaBeta['G' - 'A'] = 0b10;
        alphaBeta['T' - 'A'] = 0b11;

        std::unordered_set<unsigned int> data;
        std::unordered_set<unsigned int> repeat;

        if (s.length() < 10) {
            return vector<string>();
        }

        unsigned int v;
        for (int i = 0; i < s.length() - 10 + 1; i++) {
            v = 0;
            for (int j = 0; j < 10; j++) {
                v <<= 2;
                v |= alphaBeta[s[i + j] - 'A'];
            }

            const auto& it = data.find(v);
            if (it != data.end()) {
                repeat.insert(v);
            }
            else {
                data.insert(v);
            }
        }

        char revertAlphaBeta[] = { 'A', 'C', 'G', 'T' };

        vector<string> result;
        vector<char> toStr;
        for (auto it : repeat) {
            toStr.clear();
            for (int j = 0; j < 10; j++) {
                toStr.push_back(revertAlphaBeta[it & 0b11]);
                it >>= 2;
            }

            result.push_back(std::string(toStr.rbegin(), toStr.rend()));
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
