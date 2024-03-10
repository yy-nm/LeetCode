// 148. Sort List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

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

    std::vector< ListNode*> Arry_;

public:
    ListNode* sortList(ListNode* head) {

        if (head == nullptr)
            return head;

        int max = -100001;
        int min = 100001;

        ListNode* node = head;
        ListNode* next = nullptr;

        while (node != nullptr) {
            next = node->next;

            if (node->val > max) {
                max = node->val;
            }
            if (node->val < min) {
                min = node->val;
            }

            node = next;
        }

        int count = max - min + 1;
        Arry_.resize(count, nullptr);

        node = head;
        while (node != nullptr) {
            next = node->next;

            node->next = Arry_[node->val - min];
            Arry_[node->val - min] = node;

            node = next;
        }

        ListNode* first = nullptr;
        ListNode* prev = nullptr;

        for (const auto it : Arry_) {
            if (it == nullptr)
                continue;
            node = it;
            if (first == nullptr) {
                first = node;
            }
            if (prev != nullptr) {
                prev->next = node;
            }

            while (node->next != nullptr) {
                node = node->next;
            }
            
            prev = node;
        }

        return first;
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
