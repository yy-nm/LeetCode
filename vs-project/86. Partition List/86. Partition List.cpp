// 86. Partition List.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode head_new(-333, head);
        ListNode* p = &head_new;
        ListNode* node = p;
        ListNode* next;
        bool move = true;

        while (node != nullptr && node->next != nullptr) {
            move = true;
            next = node->next;
            if (next->val < x) {
                if (p->next->val >= x) {
                    node->next = next->next;
                    next->next = p->next;
                    p->next = next;
                    move = false;
                }

                p = p->next;
            }

            if (move)
                node = node->next;

        }

        return head_new.next;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    ListNode l1(2);
    ListNode l2(5, &l1);
    ListNode l3(2, &l2);
    ListNode l4(0, &l3);
    ListNode l5(3, &l4);
    ListNode l6(4, &l5);
    ListNode l7(1, &l6);

    Solution s;

    s.partition(&l7, 3);
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
