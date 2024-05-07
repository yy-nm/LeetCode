// 109. Convert Sorted List to Binary Search Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

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
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



namespace avl
{

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define GET_LEFT_NODE_HEIGHT(n) ((n)->lchild == nullptr ? -1 : (n)->lchild->height)
#define GET_RIGHT_NODE_HEIGHT(n) ((n)->rchild == nullptr ? -1 : (n)->rchild->height)

	template<class T>
	class Tree {

	public:
		struct Node {
			Node* lchild;
			Node* rchild;
			int height;
			T value;

			Node() : lchild(nullptr), rchild(nullptr), height(0) {}
			Node(const T& value) : value(value), lchild(nullptr), rchild(nullptr), height(0) {}

			virtual ~Node()
			{
				if (rchild != nullptr) {
					delete rchild;
					rchild = nullptr;
				}

				if (lchild != nullptr) {
					delete lchild;
					lchild = nullptr;
				}
			}
		};

		Node* root;

	public:
		Tree() : root(nullptr) {}
		virtual ~Tree()
		{
			if (root != nullptr) {
				delete root;
				root = nullptr;
			}
		}

		void Add(const T& value)
		{
			std::stack<Node*> parents;

			// find postion
			Node* node = root;
			while (nullptr != node) {
				parents.push(node);
				if (node->value < value) {
					node = node->rchild;
				}
				else if (value < node->value) {
					node = node->lchild;
				}
				else {
					// value already exists
					return;
				}
			}

			if (parents.size() == 0) {
				node = new Node(value);
				root = node;
			}
			else {
				node = new Node(value);
				Node* p = parents.top();
				if (value < p->value) {
					p->lchild = node;
				}
				else {
					p->rchild = node;
				}

				CheckRotate(parents, value);
			}
		}

	protected:

		void CheckRotate(std::stack<Tree<T>::Node*>& parents, const T& value)
		{
			int lheight = 0;
			int rheight = 0;
			while (parents.size() > 0) {
				Node* p = parents.top();
				parents.pop();

				lheight = -1;
				if (nullptr != p->lchild) {
					lheight = p->lchild->height;
				}

				rheight = -1;
				if (nullptr != p->rchild) {
					rheight = p->rchild->height;
				}

				Node* subtree = nullptr;

				if (rheight + 1 >= lheight && lheight + 1 >= rheight) {
					p->height = MAX(rheight, lheight) + 1;
				}
				else if (rheight > lheight) {
					if (p->value < value && value < p->rchild->value) {
						// double rotate
						subtree = p->rchild->lchild;

						Node* n = p->rchild;

						n->lchild = subtree->rchild;
						p->rchild = subtree->lchild;

						subtree->rchild = n;
						subtree->lchild = p;
					}
					else {
						// single rotate
						subtree = p->rchild;

						p->rchild = subtree->lchild;
						subtree->lchild = p;
					}


					// calc height
					if (nullptr != subtree->lchild) {
						subtree->lchild->height = MAX(GET_LEFT_NODE_HEIGHT(subtree->lchild), GET_RIGHT_NODE_HEIGHT(subtree->lchild)) + 1;
					}

					if (nullptr != subtree->rchild) {
						subtree->rchild->height = MAX(GET_LEFT_NODE_HEIGHT(subtree->rchild), GET_RIGHT_NODE_HEIGHT(subtree->rchild)) + 1;
					}
					subtree->height = MAX(GET_LEFT_NODE_HEIGHT(subtree), GET_RIGHT_NODE_HEIGHT(subtree)) + 1;
				}
				else if (lheight > rheight) {
					if (value < p->value && p->lchild->value < value) {
						// double rotate

						subtree = p->lchild->rchild;
						Node* n = p->lchild;

						n->rchild = subtree->lchild;
						p->lchild = subtree->rchild;

						subtree->lchild = n;
						subtree->rchild = p;
					}
					else {
						// single rotate
						subtree = p->lchild;

						p->lchild = subtree->rchild;
						subtree->rchild = p;
					}


					if (nullptr != subtree->lchild) {
						subtree->lchild->height = MAX(GET_LEFT_NODE_HEIGHT(subtree->lchild), GET_RIGHT_NODE_HEIGHT(subtree->lchild)) + 1;
					}

					if (nullptr != subtree->rchild) {
						subtree->rchild->height = MAX(GET_LEFT_NODE_HEIGHT(subtree->rchild), GET_RIGHT_NODE_HEIGHT(subtree->rchild)) + 1;
					}
					subtree->height = MAX(GET_LEFT_NODE_HEIGHT(subtree), GET_RIGHT_NODE_HEIGHT(subtree)) + 1;
				}

				if (nullptr != subtree) {
					if (parents.size() > 0) {
						p = parents.top();
						if (p->value < subtree->value)
							p->rchild = subtree;
						else
							p->lchild = subtree;
					}
					else {
						root = subtree;
					}
				}
			}
		}
	};
}

class Solution {

	void CopyTree(TreeNode* p, avl::Tree<int>::Node* q) {

		if (q->lchild != nullptr) {
			TreeNode* node = new TreeNode(q->lchild->value);
			p->left = node;
			CopyTree(node, q->lchild);
		}

		if (q->rchild != nullptr) {
			TreeNode* node = new TreeNode(q->rchild->value);
			p->right = node;
			CopyTree(node, q->rchild);
		}
	}

public:
    TreeNode* sortedListToBST(ListNode* head) {

		if (head == nullptr)
			return nullptr;

		avl::Tree<int> tree;

		ListNode* node = head;

		while (node != nullptr) {
			tree.Add(node->val);
			node = node->next;
		}

		TreeNode* root = new TreeNode(tree.root->value);
		CopyTree(root, tree.root);

		return root;
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
