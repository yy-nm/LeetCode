// 135. Candy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

        vector<int> candyCount(ratings.size(), 1);

        for (int i = 0; i < ratings.size(); i++) {
            q.push(std::make_pair(ratings[i], i));
        }

        std::pair<int, int> node;
        while (!q.empty()) {
            node = q.top();
            q.pop();

            if (node.second > 0 && node.second < ratings.size() - 1) {
                if (ratings[node.second - 1] < node.first && node.first > ratings[node.second + 1]) {
                    candyCount[node.second] = std::max(candyCount[node.second - 1], candyCount[node.second + 1]) + 1;
                }
                else if (ratings[node.second - 1] < node.first) {
                    candyCount[node.second] = candyCount[node.second - 1] + 1;
                }
                else if (node.first > ratings[node.second + 1]) {
                    candyCount[node.second] = candyCount[node.second + 1] + 1;
                }
            }
            else if (node.second == 0) {
                if (node.second + 1 < ratings.size()) {
                    if (node.first > ratings[node.second + 1]) {
                        candyCount[node.second] = candyCount[node.second + 1] + 1;
                    }
                }
            }
            else {
                if (ratings[node.second - 1] < node.first) {
                    candyCount[node.second] = candyCount[node.second - 1] + 1;
                }
            }
        }

        int result = 0;
        for (const auto& it : candyCount) {
            result += it;
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
