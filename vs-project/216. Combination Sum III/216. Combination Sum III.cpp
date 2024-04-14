// 216. Combination Sum III.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution {

    void combine(vector<vector<int>>& result, unordered_set<unsigned int>& distinct, unsigned int& used, vector<int>& now, int k, int n) {

        for (int i = 1; i < 10; i++) {
            if (used & (1 << i))
                continue;
            if (i > n)
                continue;

            used |= 1 << i;
            now.push_back(i);

            if (distinct.find(used) != distinct.end()) {
                used &= ~(1 << i);
                now.pop_back();
                continue;
            }

            if (i == n && k == 1) {
                result.push_back(now);
                distinct.insert(used);
            }
            else {
                combine(result, distinct, used, now, k - 1, n - i);
            }

            used &= ~(1 << i);
            now.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        unsigned int used;
        vector<int> now;
        unordered_set<unsigned int> distinct;
        if (n / k <= 1)
            return result;
        for (int i = 1; i < 10; i++) {
            used |= 1 << i;
            now.push_back(i);

            combine(result, distinct, used, now, k - 1, n - i);

            used &= ~(1 << i);
            now.pop_back();
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
