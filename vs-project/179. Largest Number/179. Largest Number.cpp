// 179. Largest Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Solution {

    int gcd(int a, int b) {
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a; //返回最大公约数
    }

    int lcm(int a, int b) {
        return a / gcd(a, b) * b; //计算最小公倍数
    }

    bool dealWith(const std::string& l, const std::string& r, int index) {

        int length = lcm(l.length(), r.length());

        for (int j = index; j < length; j++) {
            if (r[j % r.length()] > l[j % l.length()]) {
                return false;
            }
            else if (r[j % r.length()] < l[j % l.length()])
                return true;
        }
        return false;
    }

public:
    string largestNumber(vector<int>& nums) {

        std::vector<std::string> nums_str;
        for (const auto& it : nums) {
            nums_str.push_back(std::to_string(it));
        }

        // sort
        std::sort(nums_str.begin(), nums_str.end(), [this](const auto& l, const auto& r) -> bool {
            int length = l.length();
            if (r.length() > length) {
                length = r.length();
            }

            for (int i = 0; i < length; i++) {

                if (i >= l.length() && i >= r.length()) {
                    return false;
                }
                if (i >= l.length()) {
                    return dealWith(l, r, i);
                }
                if (i >= r.length()) {
                    return dealWith(l, r, i);
                }
                if (l[i] > r[i]) {
                    return true;
                }
                else if (l[i] < r[i]) {
                    return false;
                }
            }

            return false;
        });

        std::string result;
        for (const auto& it : nums_str) {
            result.append(it);
        }

        // remove prefix 0
        while (result.length() > 1) {
            if (result[0] > '0')
                break;
            result = result.substr(1);
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
