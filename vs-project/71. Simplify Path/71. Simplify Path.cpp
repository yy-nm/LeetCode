// 71. Simplify Path.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        vector<string> sep;

        size_t pos = 0;
        while (pos < path.length() && pos != string::npos) {
            auto new_pos = path.find_first_of('/', pos);
            if (new_pos == string::npos) {
                sep.push_back(path.substr(pos));
                break;
            }
            sep.push_back(path.substr(pos, new_pos - pos));
            pos = new_pos + 1;
        }

        vector<string> result;
        for (const auto& it : sep) {
            if (it.length() == 0)
                continue;
            if (it == ".")
                continue;
            if (it == "..") {
                if (result.size() > 0) {
                    result.pop_back();
                }
            }
            else {
                result.push_back(it);
            }
        }

        string canonical_path;
        for (const auto& it : result) {
            canonical_path.push_back('/');
            canonical_path.append(it);
        }

        if (!canonical_path.length()) {
            canonical_path.push_back('/');
        }

        return canonical_path;
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
