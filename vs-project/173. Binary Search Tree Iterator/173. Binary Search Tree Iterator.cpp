// 173. Binary Search Tree Iterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    std::stack<TreeNode*> s_;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
        while (node != nullptr) {
            s_.push(node);
            node = node->left;
        }
    }

    int next() {
        if (hasNext()) {
            TreeNode* node = s_.top();
            s_.pop();
            int result = node->val;

            node = node->right;
            while (node != nullptr) {
                s_.push(node);
                node = node->left;
            }

            return result;
        }

        return 0;
    }

    bool hasNext() {
        return !s_.empty();
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
