// 99. Recover Binary Search Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

public:

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    TreeNode* prev = nullptr;

    void travel(TreeNode* root) {

        if (root == nullptr)
            return;

        travel(root->left);
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
                second = root;
            }
            else {
                second = root;
            }
        }

        prev = root;
        travel(root->right);
    }

    void recoverTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        travel(root);

        if (first != nullptr && second != nullptr) {
            std::swap(first->val, second->val);
        }
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
