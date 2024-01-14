// 2. Add Two Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* result = new struct ListNode(0);

        struct ListNode* now = result;
        int carry = 0;
        int v = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            v = 0;
            if (l1 != nullptr) {
                v += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                v += l2->val;
                l2 = l2->next;
            }

            v += carry;
            carry = 0;

            if (v >= 10) {
                carry = 1;
                v %= 10;
            }

            now->val = v;
            if (l1 != nullptr || l2 != nullptr || carry > 0) {
                now->next = new struct ListNode(0);
                now = now->next;
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
