// 68. Text Justification.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        vector<string> lines;
        int line_len = 0;
        int word_all_len = 0;
        int add_up = 0;

        for (const auto& w : words) {
            if (line_len) {
                add_up = 1;
            }
            else {
                add_up = 0;
            }

            int word_len = w.length();

            if (add_up + line_len + word_len <= maxWidth) {
                lines.push_back(w);
                word_all_len += word_len;
                line_len += word_len + add_up;
            }
            //else if (lines.size() == 0 && word_len <= maxWidth) {
            //    lines.push_back(w);
            //    word_all_len += word_len;
            //    line_len += word_len + add_up;
            //}
            else {
                int gap = maxWidth - word_all_len;// -lines.size() - 1;
                if (gap < 0) gap = 0;
                int gap_4_word = 0;
                int gap_extra = gap;
                if (lines.size() > 1) {
                    gap_4_word = gap / (lines.size() - 1);
                    gap_extra = gap - gap_4_word * (lines.size() - 1);
                }

                string l;
                for (int i = 0; i < lines.size(); i++) {
                    string& line_word = lines.at(i);

                    if (i == 0) {
                        l.append(line_word);
                        continue;
                    }
                    l.append(string(gap_4_word, ' '));
                    if (gap_extra > 0) {
                        gap_extra--;
                        l.push_back(' ');
                    }

                    l.append(line_word);
                }

                if (gap_extra > 0) {
                    l.append(string(gap_extra, ' '));
                }

                result.push_back(l);

                lines.clear();
                word_all_len = 0;
                line_len = 0;
                lines.push_back(w);
                word_all_len += word_len;
                line_len += word_len;
            }
        }

        if (lines.size() > 0) {
            int gap = maxWidth - word_all_len - lines.size() - 1;

            string l;
            for (const auto& line_word : lines) {
                l.append(line_word);
                if (l.length() < maxWidth) {
                    l.push_back(' ');
                }
            }

            if (l.length() < maxWidth) {
                l.append(string(maxWidth - l.length(), ' '));
            }

            result.push_back(l);
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
