// 49. Group Anagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    string getTheKey(const string& str) {
        char alphabeta[26] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, };

        for (const auto& it : str) {
            alphabeta[it - 'a'] ++;
        }

        string result;
        result.reserve(str.length());

        for (int i = 0; i < sizeof(alphabeta); i++) {
            if (alphabeta[i] == 0) continue;

            result.append(alphabeta[i], 'a' + i);
        }

        return result;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> collect;

        for (const auto& it : strs) {
            const auto& k = getTheKey(it);

            auto find = collect.find(k);

            if (find != collect.end()) {
                find->second.push_back(it);
            }
            else {
                collect[k] = { it };
            }
        }

        for (const auto& it : collect) {
            result.push_back(it.second);
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
