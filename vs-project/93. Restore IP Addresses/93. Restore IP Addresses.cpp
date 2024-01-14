// 93. Restore IP Addresses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool isValid(const string& s) {
        if (s.length() > 3)
            return false;

        if (s.length() == 3) {
            if (s[0] > '2')
                return false;
            if ((s[0] == '2' && s[1] > '5'))
                return false;
            if ((s[0] == '2' && s[1] == '5' && s[2] > '5'))
                return false;
        }

        if (s[0] == '0' && s.length() > 1)
            return false;

        return true;
    }
    void generate(vector<string>& result, const string& s, int index, const string& ip, int part_count, const string& ip_part) {

        if (index == s.length() && part_count == 3 && ip_part.length() > 0) {
            result.push_back(ip + "." + ip_part);
            return;
        }

        const auto& ch = s[index];
        string now = ip_part + ch;
        if (!isValid(now)) {
            return;
        }

        generate(result, s, index + 1, ip, part_count, now);

        if (part_count < 3) {
            if (ip.length() > 0) {
                generate(result, s, index + 1, ip + "." + now, part_count + 1, "");
            }
            else {
                generate(result, s, index + 1, now, part_count + 1, "");
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        generate(result, s, 0, "", 0, "");

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
