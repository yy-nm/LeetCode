// 40. Combination Sum II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {

    void generate(const vector<int>& candidates, int index, int target, vector<int>& middle, vector<vector<int>>& result, const unordered_map<int, int>& num_count) {

        int v = candidates[index];

        int count = target / v;
        int limit = num_count.at(v);
        if (count > limit) count = limit;

        if (count * v == target) {
            vector<int> answer(count, v);
            answer.insert(answer.end(), middle.rbegin(), middle.rend());
            result.push_back(answer);
        }

        if (index < candidates.size() - 1) {
            if (middle.size() == 0) {
                for (int i = 1; i <= count; i++) {
                    if (target - i * v <= 0) {
                        continue;
                    }
                    vector<int> answer(i, v);
                    answer.insert(answer.end(), middle.begin(), middle.end());
                    generate(candidates, index + 1, target - i * v, answer, result, num_count);
                }
            }
            else {
                for (int i = 0; i <= count; i++) {
                    if (target - i * v <= 0) {
                        continue;
                    }
                    vector<int> answer(i, v);
                    answer.insert(answer.end(), middle.begin(), middle.end());
                    generate(candidates, index + 1, target - i * v, answer, result, num_count);
                }
            }
        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        unordered_map<int, int> num_count;
        for (const auto& it : candidates) {
            const auto& pair = num_count.find(it);
            if (pair != num_count.end()) {
                pair->second++;
            }
            else {
                num_count.insert(std::make_pair(it, 1));
            }
        }

        vector<int> candidates_new;
        for (const auto& it : num_count) {
            candidates_new.push_back(it.first);
        }

        std::sort(candidates_new.begin(), candidates_new.end(), std::greater<int>());

        vector<vector<int>> result;
        vector<int> v;

        for (int i = 0; i < candidates_new.size(); i++) {
            generate(candidates_new, i, target, v, result, num_count);
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
