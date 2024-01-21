// 30. Substring with Concatenation of All Words.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int alphabeta1[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
        int alphabeta2[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

        for (const auto& it : s) {
            alphabeta1[it - 'a'] ++;
        }

        unordered_map<string, int> words_count;

        int total_length = 0;
        for (const auto& w : words) {
            words_count[w] ++;
            total_length += w.length();
            for (const auto& it : w) {
                alphabeta2[it - 'a'] ++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (alphabeta2[i] > alphabeta1[i]) {
                return {};
            }
        }

        if (total_length > s.length()) {
            return {};
        }

        // ÌØÊâ´¦Àí
        if (words_count.size() == 1) {
            const auto& it = words_count.begin();

            string whole_str;
            whole_str.reserve(it->first.length() * it->second + 1);
            for (int i = 0; i < it->second; i++) {
                whole_str.append(it->first);
            }


            words_count.clear();
            words_count[whole_str] = 1;
            words.clear();
            words.push_back(whole_str);
        }

        vector<int> result;
        unordered_map<string, int> words_got;

        // start macth
        string& first = words[0];
        size_t word_length = first.length();
        int words_num = words.size();
        bool match = true;
        for (int i = 0; i < s.length() - total_length + 1; i++) {
            words_got.clear();
            if (alphabeta2[s[i] - 'a'] == 0) {
                continue;
            }
            int j = 0;
            for (j = 0; j < words_num; j++) {
                string tmp = s.substr(i + j * word_length, word_length);
                if (words_count.find(tmp) != words_count.end()) {
                    words_got[tmp]++;
                    if (words_got[tmp] > words_count[tmp]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }

            if (j == words_num) {
                result.push_back(i);
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
