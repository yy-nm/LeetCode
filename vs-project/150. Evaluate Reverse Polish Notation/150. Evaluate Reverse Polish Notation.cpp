// 150. Evaluate Reverse Polish Notation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;

        int l;
        int r;
        for (const auto& it : tokens) {
            if (it == "+") {
                if (s.size() > 1) {
                    r = s.top();
                    s.pop();
                    l = s.top();
                    s.pop();

                    s.push(l + r);
                }
                else {
                    r = s.top();
                    s.pop();
                    s.push(r);
                }
            }
            else if (it == "-") {
                if (s.size() > 1) {
                    r = s.top();
                    s.pop();
                    l = s.top();
                    s.pop();

                    s.push(l - r);
                }
                else {
                    r = s.top();
                    s.pop();
                    s.push(-r);
                }
            }
            else if (it == "*") {
                r = s.top();
                s.pop();
                l = s.top();
                s.pop();

                s.push(l * r);
            }
            else if (it == "/") {
                r = s.top();
                s.pop();
                l = s.top();
                s.pop();

                s.push(l / r);
            }
            else {
                s.push(std::stoi(it));
            }
        }

        return s.top();
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
