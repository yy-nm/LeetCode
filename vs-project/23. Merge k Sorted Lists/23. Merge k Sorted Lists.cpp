// 23. Merge k Sorted Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool loop = true;

        int index = 0;
        ListNode* result = nullptr;
        ListNode* p = nullptr;
        ListNode* n = nullptr;
        int min = 0x7fffffff;

        while (loop) {
            min = 0x7fffffff;
            index = lists.size();
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    index = i;
                }
            }

            if (index == lists.size()) {
                break;
            }

            p = lists[index];
            lists[index] = lists[index]->next;

            p->next = nullptr;

            if (nullptr == result) {
                result = n = p;
            }
            else {
                n->next = p;
                n = p;
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
