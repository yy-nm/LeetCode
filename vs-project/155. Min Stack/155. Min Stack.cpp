// 155. Min Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;


class MinStack {

    std::stack<int> data_;
    std::stack<int> mins_;

public:
    MinStack() {

    }

    void push(int val) {
        data_.push(val);
        if (mins_.empty() || mins_.top() >= val) {
            mins_.push(val);
        }
    }

    void pop() {
        if (!data_.empty()) {
            int v = data_.top();
            data_.pop();
            if (v == mins_.top())
                mins_.pop();
        }
    }

    int top() {
        if (!data_.empty())
            return data_.top();
        return 0;
    }

    int getMin() {
        if (!mins_.empty()) {
            return mins_.top();
        }

        return 0;
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
