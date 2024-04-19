// 236. Lowest Common Ancestor of a Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    bool getParents(TreeNode* node, std::vector< TreeNode*>& list, int v)
    {
        if (node->val == v) {
            list.push_back(node);
            return true;
        }
        if (node->left != nullptr) {
            if (getParents(node->left, list, v)) {
                list.push_back(node);
                return true;
            }
        }
        if (node->right != nullptr) {
            if (getParents(node->right, list, v)) {
                list.push_back(node);
                return true;
            }
        }

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        std::vector< TreeNode*> parent_list_p;
        std::vector< TreeNode*> parent_list_q;
        std::unordered_set< TreeNode* > set_p;
        std::unordered_set< TreeNode* > set_q;

        getParents(root, parent_list_p, p->val);
        getParents(root, parent_list_q, q->val);

        for (const auto& it : parent_list_p) {
            set_p.insert(it);
        }

        for (const auto& it : parent_list_q) {
            const auto& find_it = set_p.find(it);
            if (find_it != set_p.end()) {
                return it;
            }
        }

        return nullptr;
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
