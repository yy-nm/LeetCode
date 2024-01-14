// 10. Regular Expression Matching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:

    bool match(string s, string p, vector<int> validCast, int index_s, int index_p, int index) {
        if (index >= validCast.size()) {
            while (index_s < s.length() && index_p < p.length()) {
                if (s[index_s++] != p[index_p++]) {
                    return false;
                }
            }

            if (index_s == s.length() && index_p == p.length()) {
                return true;
            }

            return false;
        }

        if (index_p >= p.length() && index_s >= s.length()) {
            return true;
        }

        if (index_p >= p.length()) {
            return false;
        }

        if (index_s >= s.length()) {

            if (index_p < p.length()) {
                if (p[index_p] == '*') {
                    return match(s, p, validCast, index_s, index_p + 1, index + 1);
                }
                else if (p[index_p] != '.' && index_p + 1 < p.length() && p[index_p + 1] == '*') {
                    return match(s, p, validCast, index_s, index_p + 2, index + 1);
                }
                else if (p[index_p] == '.' && index_p + 1 < p.length() && p[index_p + 1] == '*') {
                    return match(s, p, validCast, index_s, index_p + 2, index + 2);
                }
            }

            return false;
        }

        if (index_p < validCast[index]) {
            if (index_p + 1 != validCast[index] || p[validCast[index]] == '.') {
                if (s[index_s] != p[index_p]) {
                    //return match(s, p, validCast, index_s, index_p + 1, index);
                    return false;
                }
                return match(s, p, validCast, index_s + 1, index_p + 1, index);
            }
            else {
                //if (p[validCast[index]] == '*') {
                //    char repeatValue = p[validCast[index] - 1];
                //    if (repeatValue == '.') {
                //        if (validCast[index] == p.length() - 1) {
                //            return true;
                //        }
                //        else {
                //            for (int i = index_s; i < s.length(); i++) {

                //                if (match(s, p, validCast, i + 1, index_p + 2, index + 1)) {
                //                    return true;
                //                }
                //            }
                //        }
                //    }
                //    else {
                //        for (int i = index_s; i < s.length(); i++) {
                //            if (s[i] == repeatValue) {
                //                if (match(s, p, validCast, i + 1, index_p + 2, index + 1)) {
                //                    return true;
                //                }
                //            }
                //            else {
                //                break;
                //            }
                //        }
                //        return match(s, p, validCast, index_s, index_p + 2, index + 1);
                //    }
                //}
                return match(s, p, validCast, index_s, index_p + 1, index);
            }
        }
        else {
            if (p[validCast[index]] == '*') {
                char repeatValue = p[validCast[index] - 1];
                if (repeatValue == '.') {
                    if (validCast[index] == p.length() - 1) {
                        return true;
                    }
                    else {

                        for (int i = index_s; i < s.length(); i++) {

                            if (match(s, p, validCast, i + 1, index_p + 1, index + 1)) {
                                return true;
                            }


                        }
                        return match(s, p, validCast, index_s, index_p + 1, index + 1);
                    }
                }
                else {
                    for (int i = index_s; i < s.length(); i++) {
                        if (s[i] == repeatValue) {
                            if (match(s, p, validCast, i + 1, index_p + 1, index + 1)) {
                                return true;
                            }
                        }
                        else {
                            break;
                        }
                    }
                    return match(s, p, validCast, index_s, index_p + 1, index + 1);
                }
            }
            else {

                if (index_p + 1 < p.length() && p[index_p + 1] == '*') {

                    return match(s, p, validCast, index_s, index_p + 1, index + 1);
                }

                return match(s, p, validCast, index_s + 1, index_p + 1, index + 1);
            }
        }

        return false;
    }


    bool isMatch(string s, string p) {

        vector<int> indexes;
        unordered_map<char, int> count_s, count_p;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '.' || p[i] == '*') {
                indexes.push_back(i);
            }
            if (!count_p.count(p[i])) {
                count_p[p[i]] = 1;
            }
            else {
                count_p[p[i]] += 1;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (!count_s.count(s[i])) {
                count_s[s[i]] = 1;
            }
            else {
                count_s[s[i]] += 1;
            }
        }

        if (count_p.count('*') && count_p.count('.')) {

        }
        else {
            for (const auto& it : count_s) {
                if (!count_p.count(it.first) && count_p.count('.') < it.second) {
                    return false;
                }
            }
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '*' || p[i] == '.') {
                continue;
            }
            if (!count_s.count(p[i]) && (i == p.size() - 1 || p[i + 1] != '*')) {
                return false;
            }
        }

        if (indexes.size() == 0) {
            if (s == p) {
                return true;
            }
            return false;
        }

        return match(s, p, indexes, 0, 0, 0);
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Solution s;

    //string str1 = "aaaaaaaaaaaaaaaaaaab";
    //string str2 = "a*a*a*a*a*a*a*a*a*a*";
    //string str1 = "aa";
    //string str2 = "a*";
      string str1 = "aaaaaaaaaaaaaaaaaaa";
    string str2 = "a*a*a*a*a*a*a*a*a*a*b";
    std::cout << s.isMatch(str1, str2);

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
