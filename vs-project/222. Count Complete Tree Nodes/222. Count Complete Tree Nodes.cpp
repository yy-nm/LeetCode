// 222. Count Complete Tree Nodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    int getHeight(TreeNode* node) {
        if (nullptr == node)
            return 0;

        int left = getHeight(node->left);
        int right = getHeight(node->right);

        return 1 + std::min(left, right);
    }

    int getCount(TreeNode* node, int level) {
        if (level < 0 || node == nullptr)
            return 0;

        int count = 1;
        if (level == 0)
            return count;

        if (node->left != nullptr) {
            count += getCount(node->left, level - 1);
        }
        if (node->right != nullptr) {
            count += getCount(node->right, level - 1);
        }

        return count;
    }

public:
    int countNodes(TreeNode* root) {

        int result = 0;

        if (root == nullptr) {
            return result;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        int level = std::min(left, right);

        result = 1 + getCount(root->left, level) + getCount(root->right, level);

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
