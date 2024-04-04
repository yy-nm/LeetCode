// 201. Bitwise AND of Numbers Range.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    unsigned int countBits(unsigned int l, unsigned int r) {

        unsigned int result = l;

        for (int i = 0; i < 16; i++) {
            if (l == r)
                break;

            l++;
            if (l > 0xf) {
                l &= 0xf;
            }

            result &= l;
        }

        return result;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        std::vector<unsigned int> result;

        if (left == right)
            return left;

        unsigned int l = left;
        unsigned int r = right;

        unsigned int ll = 0;
        unsigned int rr = 0;
        for (int i = 0; i < 8; i++) {
            ll = l & 0xf;
            rr = r & 0xf;
            l >>= 4;
            r >>= 4;

            if (r >= l + 2 || ll > rr || ll == 0 || rr == 0) {
                result.push_back(0);
            }
            else if (r == l + 1 && rr >= ll) {
                result.push_back(0);
            }
            else {
                result.push_back(countBits(ll, rr));
            }

        }

        unsigned int num = 0;
        for (int i = 0; i < result.size(); i++) {
            num |= result[i] << (4 * i);
        }

        return num;
    }
};


int main()
{
    std::cout << "Hello World!\n";

    Solution s;

    std::cout << s.rangeBitwiseAnd(16, 17) << std::endl;
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
