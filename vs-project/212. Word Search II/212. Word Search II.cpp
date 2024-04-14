// 212. Word Search II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;



struct Trie {

    struct Node {
        std::vector<struct Node*> m_vAlphaBeta;
        bool HasWord;
        bool AllMatched;

        Node() : HasWord(false), m_vAlphaBeta(26, nullptr), AllMatched(false) {}
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
};

class Solution {

    bool Match(const vector<vector<char>>& board, vector<vector<bool>>& used, string& word, int i, int j, vector<string>& result, Trie::Node* node) {

        if (used[i][j])
            return false;
        if (node->AllMatched)
            return false;

        used[i][j] = true;

        int count = 0;

        for (int index = 0; index < node->m_vAlphaBeta.size(); index++) {
            if (node->m_vAlphaBeta[index] == nullptr)
                continue;

            count++;
            char v = 'a' + index;
            word.push_back(v);

            if (i >= 1 && !used[i - 1][j] && board[i - 1][j] == v) {
                if (Match(board, used, word, i - 1, j, result, node->m_vAlphaBeta[index])) {
                    //used[i][j] = false;
                    //return true;
                }
            }

            if (i < board.size() - 1 && board[i + 1][j] == v) {
                if (Match(board, used, word, i + 1, j, result, node->m_vAlphaBeta[index])) {
                    //used[i][j] = false;
                    //return true;
                }
            }

            if (j >= 1 && !used[i][j - 1] && board[i][j - 1] == v) {
                if (Match(board, used, word, i, j - 1, result, node->m_vAlphaBeta[index])) {
                    //used[i][j] = false;
                    //return true;
                }
            }

            if (j < board[i].size() - 1 && board[i][j + 1] == v) {
                if (Match(board, used, word, i, j + 1, result, node->m_vAlphaBeta[index])) {
                    //used[i][j] = false;
                    //return true;
                }
            }

            word.pop_back();
        }

        if (node->HasWord) {
            result.push_back(word);
            node->HasWord = false;
            if (count == 0) {
                node->AllMatched = true;
            }
        }

        if (!node->AllMatched) {
            bool allMatched = true;
            for (int index = 0; index < node->m_vAlphaBeta.size(); index++) {
                if (node->m_vAlphaBeta[index] && !node->m_vAlphaBeta[index]->AllMatched) {
                    allMatched = false;
                    break;
                }
            }

            if (allMatched) {
                node->AllMatched = true;
            }
        }

        used[i][j] = false;
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));

        vector<vector<pair<int, int>>> indexes(26, vector<pair<int, int>>());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                indexes[board[i][j] - 'a'].push_back(std::make_pair(i, j));
            }
        }

        vector<string> result;
        Trie t;

        for (const auto& it : words) {
            t.insert(it);
        }

        //for (const auto& it : words) {
        //    for (const auto& pos : indexes[it[0] - 'a']) {
        //        if (Match(board, indexes, used, it, 0, pos.first, pos.second)) {
        //            result.push_back(it);
        //            break;
        //        }
        //    }
        //} 

        string s;
        for (int i = 0; i < t.m_pRoot->m_vAlphaBeta.size(); i++) {
            if (t.m_pRoot->m_vAlphaBeta[i] == nullptr)
                continue;
            for (const auto& pos : indexes[i]) {
                s.clear();
                s.push_back('a' + i);
                Match(board, used, s, pos.first, pos.second, result, t.m_pRoot->m_vAlphaBeta[i]);
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
