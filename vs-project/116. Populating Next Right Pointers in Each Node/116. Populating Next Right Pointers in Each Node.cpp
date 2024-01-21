// 116. Populating Next Right Pointers in Each Node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> level;
        std::queue<Node*> level_can;

        Node* prev = nullptr;
        Node* node = nullptr;

        if (root == nullptr)
            return root;

        level.emplace(root);

        while (!level.empty()) {
            while (!level.empty()) {

                node = level.front();
                level.pop();

                if (prev != nullptr) {
                    prev->next = node;
                }
                prev = node;

                if (node->left != nullptr) {
                    level_can.emplace(node->left);
                }
                if (node->right != nullptr) {
                    level_can.emplace(node->right);
                }
            }

            prev = nullptr;
            node = nullptr;
            level.swap(level_can);
        }

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
