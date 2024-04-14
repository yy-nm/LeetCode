// 211. Design Add and Search Words Data Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class WordDictionary {

    struct Node {
        std::vector<Node*> alphaBeta;
        bool bHasWords;

        Node() : alphaBeta(26, nullptr), bHasWords(false) {}
    };

    Node* m_pRoot;

    bool search(const string& word, Node* p, int index) {
        if (index >= word.length()) {
            return p->bHasWords;
        }
        if (word[index] == '.') {
            for (const auto& it : p->alphaBeta) {
                if (it == nullptr)
                    continue;
                if (search(word, it, index + 1))
                    return true;
            }
        }
        else {
            if (p->alphaBeta[word[index] - 'a'] == nullptr)
                return false;

            return search(word, p->alphaBeta[word[index] - 'a'], index + 1);
        }

        return false;
    }

public:
    WordDictionary() {
        m_pRoot = new Node();
    }

    void addWord(string word) {
        Node* p = m_pRoot;

        for (const auto& it : word) {
            if (p->alphaBeta[it - 'a'] == nullptr) {
                p->alphaBeta[it - 'a'] = new Node();
            }
            p = p->alphaBeta[it - 'a'];
        }

        p->bHasWords = true;
    }

    bool search(string word) {

        bool bHasValid = false;
        for (const auto& it : word) {
            if (it == '.') {
                bHasValid = true;
                break;
            }
        }

        Node* p = m_pRoot;
        if (bHasValid) {
            return search(word, p, 0);
        }
        else {
            for (int i = 0; i < word.length(); i++) {
                if (p->alphaBeta[word[i] - 'a'] == nullptr) {
                    return false;
                }
                p = p->alphaBeta[word[i] - 'a'];
            }

            return p->bHasWords;
        }
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
