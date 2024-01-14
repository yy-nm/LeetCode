// 82. Remove Duplicates from Sorted List II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode head_new(101, head);
        ListNode* p = &head_new;

        ListNode* node = p;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;

        while (node->next != nullptr && node->next->next != nullptr) {
            next1 = node->next;
            next2 = next1->next;

            if (next1->val != next2->val) {
                node = node->next;
            }
            else {
                int v = next1->val;
                while (node->next != nullptr && node->next->val == v) {
                    node->next = node->next->next;
                }
            }
        }

        return p->next;
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
