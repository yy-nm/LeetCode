// 110. Balanced Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    bool getHeight(TreeNode* node, int& height) {

        if (node == nullptr) {
            height = 0;
            return true;
        }

        int height_left = 0;
        int height_right = 0;
        if (node->left != nullptr) {
            if (!getHeight(node->left, height_left))
                return false;
        }
        if (node->right != nullptr) {
            if (!getHeight(node->right, height_right))
                return false;
        }

        height = std::max(height_left, height_right) + 1;

        if (std::fabs(height_left - height_right) > 1) {
            return false;
        }

        return true;
    }

public:
    bool isBalanced(TreeNode* root) {

        if (root == nullptr)
            return true;

        int height = 0;

        return getHeight(root, height);
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
