// 21. Merge Two Sorted Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (nullptr == list1) {
            return list2;
        }
        else if (nullptr == list2) {
            return list1;
        }

        ListNode* p = list1;
        ListNode* q = list2;

        ListNode* result = nullptr;
        ListNode* n = nullptr;
        ListNode* c = nullptr;

        while (p != nullptr || q != nullptr) {

            if (p != nullptr && q != nullptr) {
                if (p->val < q->val) {
                    c = p;
                    p = p->next;

                    c->next = nullptr;
                    if (result == nullptr) {
                        result = n = c;
                    }
                    else {
                        n->next = c;
                        n = n->next;
                    }
                }
                else {
                    c = q;
                    q = q->next;
                    c->next = nullptr;

                    if (result == nullptr) {
                        result = n = c;
                    }
                    else {
                        n->next = c;
                        n = n->next;
                    }
                }
            }
            else if (p != nullptr) {
                if (result == nullptr) {
                    result = n = p;
                }
                else {
                    n->next = p;
                }
                break;
            }
            else {
                if (result == nullptr) {
                    result = n = q;
                }
                else {
                    n->next = q;
                }
                break;
            }
        }

        return result;
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
