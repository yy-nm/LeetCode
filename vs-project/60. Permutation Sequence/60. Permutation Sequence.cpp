// 60. Permutation Sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;


class Solution {

    static int factorial[10];

    int generate(int n) {
        if (n <= 1) {
            factorial[n] = 1;
            return 1;
        }
        else {
            factorial[n] = n * generate(n - 1);
            return factorial[n];
        }
    }

public:
    string getPermutation(int n, int k) {

        if (factorial[n] == 0) {
            generate(n);
        }

        unordered_set<int> nums;
        string result;

        bool compensate = false;

        for (int i = 1; i <= n; i++) {
            int v = factorial[n - i];
            if (k > v) {
                int time = k / v;
                k = k % v;

                if (k == 0) {
                    time--;
                    k = v;
                }

                int j = 1;
                while (time > 0 || nums.count(j)) {
                    if (!nums.count(j)) {
                        time--;
                    }
                    j++;
                    if (j >= n) {
                        j = n;
                        break;
                    }
                }

                //if (j > n) {
                //    j = n;
                //}

                result.push_back('0' + j);
                nums.insert(j);

                if (k == 0) {
                    compensate = true;
                }
            }
            else {
                for (int j = 1; j <= n; j++) {
                    if (!nums.count(j)) {
                        if (compensate) {
                            compensate = false;
                            continue;
                        }
                        result.push_back('0' + j);
                        nums.insert(j);
                        break;
                    }
                }
                compensate = false;
            }

            if (k == 0) {
                break;
            }
        }

        if (result.size() != n) {
            for (int j = 1; j <= n; j++) {
                if (!nums.count(j)) {
                    result.push_back('0' + j);
                    nums.insert(j);
                }
            }
        }

        return result;
    }
};

int Solution::factorial[10] = { 1, 1 };

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
