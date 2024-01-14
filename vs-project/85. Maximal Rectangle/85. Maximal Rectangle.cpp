// 85. Maximal Rectangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
    int largestRectangleArea(const vector<int>& heights) {

        int result = 0;
        int n = heights.size();
        vector<int> begin(n, 0);
        vector<int> end(n, n - 1);

        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                begin[s.top()] = i + 1;
                s.pop();
            }

            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                end[s.top()] = i - 1;
                s.pop();
            }

            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            int w = end[i] - begin[i] + 1;
            if (w * heights[i] > result) {
                result = w * heights[i];
            }
        }


        return result;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp_middle;

        for (int i = 0; i < matrix.size(); i++) {
            const auto& line = matrix.at(i);
            dp_middle.push_back(vector<int>(line.size(), 0));

            for (int j = 0; j < line.size(); j++) {

                if (line[j] == '1') {
                    if (i > 0) {
                        dp_middle.at(i).at(j) = 1 + dp_middle.at(i - 1).at(j);
                    }
                    else {
                        dp_middle.at(i).at(j) = 1;
                    }
                }
            }
        }

        int max = 0;
        for (const auto& it : dp_middle) {
            int v = largestRectangleArea(it);
            if (v > max) max = v;
        }

        return max;
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
