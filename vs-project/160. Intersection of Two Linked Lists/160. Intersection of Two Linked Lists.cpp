// 160. Intersection of Two Linked Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        std::unordered_set<ListNode*> nodes;

        ListNode* pNode = headA;

        while (pNode != nullptr) {
            nodes.insert(pNode);
            pNode = pNode->next;
        }

        pNode = headB;

        while (pNode != nullptr) {

            const auto& it = nodes.find(pNode);
            if (it != nodes.end()) {
                return pNode;
            }

            pNode = pNode->next;
        }

        return nullptr;
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
