// 24. Swap Nodes in Pairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* swapPairs(ListNode* head) {

        return reverseKGroup(head, 2);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode result;
        ListNode* pHead = &result;
        pHead->next = nullptr;

        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* p = pHead;
        ListNode* c = nullptr;
        int index = 0;
        while (head) {
            c = head;
            head = head->next;
            c->next = nullptr;

            c->next = p->next;
            p->next = c;

            index++;

            if (index == k) {
                while (--index >= 0) {
                    p = p->next;
                }
                index = 0;
            }
        }

        // reverse again to become right order
        if (index > 1) {
            head = p->next;
            p->next = nullptr;
            while (head) {
                c = head;
                head = head->next;
                c->next = nullptr;

                c->next = p->next;
                p->next = c;
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
