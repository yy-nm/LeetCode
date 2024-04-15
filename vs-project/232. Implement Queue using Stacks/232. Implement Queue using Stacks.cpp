// 232. Implement Queue using Stacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;


class MyQueue {

    std::stack<int> s;

    void push(std::stack<int>& s, int x) {

        if (s.empty()) {
            s.push(x);
            return;
        }

        int v = s.top();
        s.pop();
        push(s, x);
        s.push(v);
    }

public:
    MyQueue() {

    }

    void push(int x) {
        push(s, x);
    }

    int pop() {
        if (!empty()) {
            int v = s.top();
            s.pop();

            return v;
        }

        return 0;
    }

    int peek() {
        if (empty())
            return 0;
        return s.top();
    }

    bool empty() {
        return s.empty();
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
