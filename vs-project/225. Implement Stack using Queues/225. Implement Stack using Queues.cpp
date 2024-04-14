// 225. Implement Stack using Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;


class MyStack {

    std::queue<int> q;
    std::queue<int> q_out;

    void convert(std::queue<int>& in, std::queue<int>& out) {
        if (in.empty()) {
            while (!out.empty()) {
                in.push(out.front());
                out.pop();
            }
            return;
        }
        int v = in.front();
        in.pop();
        convert(in, out);
        out.push(v);
    }

public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        if (empty())
            return 0;
        if (!q.empty()) {
            convert(q, q_out);

            while (!q.empty()) {
                q_out.push(q.front());
                q.pop();
            }
        }

        int v = q_out.front();
        q_out.pop();

        return v;
    }

    int top() {
        if (empty())
            return 0;
        if (!q.empty()) {
            convert(q, q_out);
            while (!q.empty()) {
                q_out.push(q.front());
                q.pop();
            }
        }

        int v = q_out.front();
        return v;
    }

    bool empty() {
        return q.empty() && q_out.empty();
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
