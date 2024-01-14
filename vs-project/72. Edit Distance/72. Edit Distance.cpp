// 72. Edit Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// accepted one
class Solution {
public:
    int minDistance(string word1, string word2) {

        if (word2.size() > word2.size()) {
            swap(word2, word1);
        }

        vector<vector<int>> vv(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 1; i <= word1.size(); i++) {
            vv.at(i).at(0) = i;
        }
        for (int j = 1; j <= word2.size(); j++) {
            vv.at(0).at(j) = j;
        }


        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    vv.at(i).at(j) = vv.at(i - 1).at(j - 1);
                }
                else {
                    int m = vv.at(i - 1).at(j - 1);
                    if (m > vv.at(i - 1).at(j)) {
                        m = vv.at(i - 1).at(j);
                    }
                    if (m > vv.at(i).at(j - 1)) {
                        m = vv.at(i).at(j - 1);
                    }
                    vv.at(i).at(j) = m + 1;
                }
            }

        }

        if (word1.size() == 0 || word2.size() == 0) {
            return word1.size() + word2.size();
        }

        return vv.at(word1.size()).at(word2.size());
    }
};

int main()
{
    std::cout << "Hello World!\n";
    string s1 = "pneumonoultramicroscopicsilicovolcanoconiosis";
    string s2 = "ultramicroscopically";
    Solution s;
    std::cout << s.minDistance(s1, s2) << std::endl;
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
