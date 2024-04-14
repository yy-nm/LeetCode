// 208. Implement Trie (Prefix Tree).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Trie {

    struct Node {
        std::vector<struct Node*> m_vAlphaBeta;
        bool HasWord;

        Node() : HasWord(false), m_vAlphaBeta(26, nullptr) {}
    };

    struct Node* m_pRoot;

public:
    Trie() {
        m_pRoot = new Node();
    }

    void insert(string word) {
        struct Node* node = m_pRoot;
        for (const auto& it : word) {
            if (node->m_vAlphaBeta[it - 'a'] == nullptr) {
                node->m_vAlphaBeta[it - 'a'] = new Node();
            }

            node = node->m_vAlphaBeta[it - 'a'];
        }

        if (word.length() > 0) {
            node->HasWord = true;
        }
    }

    bool search(string word) {
        struct Node* node = m_pRoot;
        for (const auto& it : word) {
            if (node->m_vAlphaBeta[it - 'a'] == nullptr)
                return false;
            node = node->m_vAlphaBeta[it - 'a'];
        }

        return node != nullptr && node->HasWord;
    }

    bool startsWith(string prefix) {
        struct Node* node = m_pRoot;
        for (const auto& it : prefix) {
            if (node->m_vAlphaBeta[it - 'a'] == nullptr)
                return false;
            node = node->m_vAlphaBeta[it - 'a'];
        }

        return node != nullptr;
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
