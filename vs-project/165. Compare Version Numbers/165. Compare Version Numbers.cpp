// 165. Compare Version Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

    void getVersionList(const string& v, std::vector<int>& out) {

        int pos = 0;
        int end = 0;

        while (pos != v.npos) {
            end = v.find('.', pos);
            if (end != v.npos) {
                out.push_back(std::stoi(v.substr(pos, end - pos)));
            }
            else {
                out.push_back(std::stoi(v.substr(pos, end)));
                break;
            }

            pos = end + 1;
        }
    }

public:
    int compareVersion(string version1, string version2) {

        std::vector<int> versionList1;
        std::vector<int> versionList2;

        getVersionList(version1, versionList1);
        getVersionList(version2, versionList2);

        int len = versionList1.size();
        if (versionList2.size() > len) {
            len = versionList2.size();
        }

        for (int i = 0; i < len; i++) {
            if (i >= versionList1.size()) {
                if (versionList2[i] > 0)
                    return -1;
            }
            if (i >= versionList2.size()) {
                if (versionList1[i] > 0)
                    return 1;
            }

            if (i < versionList1.size() && i < versionList2.size()) {
                if (versionList1[i] > versionList2[i])
                    return 1;
                else if (versionList1[i] < versionList2[i])
                    return -1;
            }
        }

        return 0;
    }
};


int main()
{
    std::cout << "Hello World!\n";

    Solution s;
    std::string s1 = "1.01";
    std::string s2 = "1.001";

    std::cout << s.compareVersion(s1, s2) << std::endl;
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
