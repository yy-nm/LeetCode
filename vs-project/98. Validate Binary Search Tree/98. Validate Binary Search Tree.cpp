// 98. Validate Binary Search Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    bool getMaxValue(TreeNode* node, int& value) {
        if (node->right != nullptr) {
            if (!getMaxValue(node->right, value)) {
                return false;
            }

            if (node->val >= value) {
                return false;
            }
        }
        else {
            value = node->val;
        }

        return true;
    }

    bool getMinValue(TreeNode* node, int& value) {
        if (node->left != nullptr) {
            if (!getMinValue(node->left, value)) {
                return false;
            }

            if (node->val <= value) {
                return false;
            }
        }
        else {
            value = node->val;
        }

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        int v = 0;
        if (root->left != nullptr) {
            if (root->left->val >= root->val) {
                return false;
            }

            if (!isValidBST(root->left)) {
                return false;
            }

            if (!getMaxValue(root->left, v) || v >= root->val) {
                return false;
            }
        }
        if (root->right != nullptr) {
            if (root->right->val <= root->val) {
                return false;
            }

            if (!isValidBST(root->right)) {
                return false;
            }

            if (!getMinValue(root->right, v) || v <= root->val) {
                return false;
            }
        }

        return true;
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
