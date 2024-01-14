// 92. Reverse Linked List II.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode result(0, head);
        ListNode* node = &result;
        ListNode* next = nullptr;
        ListNode* p = nullptr;
        ListNode* matched_head = nullptr;

        int pos = 0;
        bool matched = false;
        while (node->next != nullptr) {
            next = node->next;
            pos++;

            if (!matched) {
                if (pos >= left && pos < right) {
                    matched = true;
                    matched_head = node;
                }
                node = node->next;

            }
            else {
                node->next = next->next;
                next->next = matched_head->next;
                matched_head->next = next;

                if (pos >= right) {
                    matched = false;
                    break;
                }
            }

            if (node == nullptr) {
                break;
            }
        }

        return result.next;
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
