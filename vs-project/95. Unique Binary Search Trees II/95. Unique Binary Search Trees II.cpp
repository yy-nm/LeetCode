// 95. Unique Binary Search Trees II.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


class Solution {

    static vector<vector<TreeNode*>> s_cacheResult;

    TreeNode* dumpTree(TreeNode* src) {
        TreeNode* result = nullptr;
        if (src != nullptr) {
            result = new TreeNode();
            result->val = src->val;
            if (src->left != nullptr) {
                result->left = dumpTree(src->left);
            }
            if (src->right != nullptr) {
                result->right = dumpTree(src->right);
            }
        }

        return result;
    }

    void markValue(TreeNode* node, int& value) {

        if (node->left != nullptr) {
            markValue(node->left, value);
        }
        node->val = value++;
        if (node->right != nullptr) {
            markValue(node->right, value);
        }
    }

    void generate(int n) {
        if (s_cacheResult.at(n).size() == 0) {

            if (n == 0) {
                s_cacheResult.at(n).push_back(nullptr);
            }
            else if (n == 1) {
                TreeNode* root = new TreeNode();
                root->val = 1;
                s_cacheResult.at(n).push_back(root);
            }
            else {
                for (int i = 0; i < n; i++) {
                    //v += generate(i) * generate(n - i - 1);
                    generate(i); // left subtree
                    generate(n - i - 1); // right subtree

                    vector<TreeNode*> l = s_cacheResult.at(i);
                    vector<TreeNode*> r = s_cacheResult.at(n - i - 1);

                    
                    for (const auto& it_l : l) {
                        for (const auto& it_r : r) {
                            TreeNode* root = new TreeNode();
                            root->left = dumpTree(it_l);
                            root->right = dumpTree(it_r);
                            int v = 1;
                            markValue(root, v);
                            s_cacheResult.at(n).push_back(root);
                        }
                    }
                }
            }
        }
    }

    void generate(vector<TreeNode*>& result, int n) {

        generate(n);

        for (const auto& it : s_cacheResult.at(n)) {
            result.push_back(dumpTree(it));
        }
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        //TreeNode* root = new TreeNode();
        generate(result, n);


        //for (auto& it : result) {
        //    int v = 1;
        //    markValue(it, v);
        //}

        return result;
    }
};

vector<vector<TreeNode*>> Solution::s_cacheResult(10);

int main()
{
    std::cout << "Hello World!\n";

    Solution s;

    s.generateTrees(1);
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
