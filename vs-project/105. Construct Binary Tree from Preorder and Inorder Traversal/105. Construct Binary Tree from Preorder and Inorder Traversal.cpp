// 105. Construct Binary Tree from Preorder and Inorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

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

    size_t find(const vector<int>& v, int target) {
        for (int i = 0; i < v.size(); i++) {
            if (v.at(i) == target)
                return i;
        }

        return -1;
    }

    TreeNode* buildLeftTree(vector<int>& preorder, int pre_index_begin, int pre_index_end, vector<int>& inorder, int in_index_begin, int in_index_end) {
        if (pre_index_begin > pre_index_end)
            return nullptr;
        int v = preorder[pre_index_begin];
        int index = find(inorder, v);

        TreeNode* node = new TreeNode(v);

        int len_left = index - in_index_begin;

        node->left = buildLeftTree(preorder, pre_index_begin + 1, pre_index_begin + len_left, inorder, in_index_begin, index - 1);
        node->right = buildLeftTree(preorder, pre_index_begin + len_left + 1, pre_index_end, inorder, index + 1, in_index_end);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int v = preorder[0];
        int index = find(inorder, v);

        TreeNode* root = new TreeNode(v);

        int len_left = index;

        root->left = buildLeftTree(preorder, 1, 1 + len_left - 1, inorder, 0, index - 1);
        root->right = buildLeftTree(preorder, 1 + len_left, preorder.size() - 1, inorder, index + 1, inorder.size() - 1);

        return root;
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
