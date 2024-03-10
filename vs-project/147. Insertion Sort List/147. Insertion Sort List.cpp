// 147. Insertion Sort List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    void insert(ListNode* root, ListNode* node) {
        ListNode* next = nullptr;

        while (root->next != nullptr) {
            next = root->next;
            if (next->val > node->val) {
                node->next = next;
                root->next = node;
                break;
            }

            root = next;
        }

        if (root->next == nullptr) {
            root->next = node;
        }
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode root;
        ListNode* node = nullptr;
        ListNode* next = nullptr;

        node = head;
        while (node != nullptr) {
            next = node->next;

            node->next = nullptr;
            insert(&root, node);

            node = next;
        }

        return root.next;
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
