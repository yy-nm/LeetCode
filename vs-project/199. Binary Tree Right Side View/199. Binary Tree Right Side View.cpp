// 199. Binary Tree Right Side View.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (nullptr == root)
            return result;

        std::queue<std::pair< TreeNode*, int>> q;
        int level = -1;
        q.push(std::make_pair(root, 0));

        std::pair< TreeNode*, int> n;

        while (!q.empty()) {
            n = q.front();
            q.pop();

            if (n.second > level) {
                result.push_back(n.first->val);
                level = n.second;
            }

            if (n.first->right != nullptr) {
                q.push(std::make_pair(n.first->right, n.second + 1));
            }
            if (n.first->left != nullptr) {
                q.push(std::make_pair(n.first->left, n.second + 1));
            }
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
