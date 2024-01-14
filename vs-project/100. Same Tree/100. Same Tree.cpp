// 100. Same Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (nullptr == p && nullptr == q) {
            return true;
        }

        if (nullptr == p || nullptr == q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        if (p->left != nullptr && q->left != nullptr) {
            if (!isSameTree(p->left, q->left)) {
                return false;
            }
        }
        else if (p->left == nullptr && q->left == nullptr) {

        }
        else {
            return false;
        }

        if (p->right != nullptr && q->right != nullptr) {
            if (!isSameTree(p->right, q->right)) {
                return false;
            }
        }
        else if (p->right == nullptr && q->right == nullptr) {

        }
        else {
            return false;
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
