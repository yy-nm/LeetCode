// 207. Course Schedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {

    bool canLearn(int index, std::vector<bool>& learned, std::unordered_set<int> dep, const std::unordered_map<int, std::unordered_set<int>>& pre) {
        const auto& find_it = dep.find(index);
        if (find_it != dep.end()) {
            return false;
        }

        if (learned[index])
            return true;

        const auto& p_it = pre.find(index);
        if (p_it == pre.end()) {
            return true;
        }

        dep.insert(index);

        for (const auto& it : p_it->second) {
            if (!canLearn(it, learned, dep, pre))
                return false;
        }

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<bool> learned(numCourses, false);
        std::unordered_map<int, std::unordered_set<int>> pre;

        for (const auto& it : prerequisites) {
            const auto& find_it = pre.find(it[0]);
            if (find_it != pre.end()) {
                pre[it[0]].insert(it.begin() + 1, it.end());
            }
            else {
                pre[it[0]] = std::unordered_set<int>(it.begin() + 1, it.end());
            }
        }
        std::unordered_set<int> dep;

        for (int i = 0; i < numCourses; i++) {
            if (learned[i]) {
                continue;
            }
            else {
                dep.clear();
                if (!canLearn(i, learned, dep, pre)) {
                    return false;
                }

                for (const auto& it : dep) {
                    learned[it] = true;
                }

                learned[i] = true;
            }
        }

        return true;
    }
};


int main()
{
    std::cout << "Hello World!\n";

    Solution s;
    vector<vector<int>> v = { {1,0}, {1,2}, {0, 1} };

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
