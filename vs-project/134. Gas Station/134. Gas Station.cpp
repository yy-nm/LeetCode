// 134. Gas Station.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        vector<int> benifit(gas.size(), 0);

        int total_gas = 0;
        int total_cost = 0;
        for (int i = 0; i < gas.size(); i++) {
            benifit[i] = gas[i] - cost[i];
            total_cost += cost[i];
            total_gas += gas[i];
        }

        if (total_cost > total_gas)
            return -1;

        int index = -1;
        int value = 0;
        for (int i = 0; i <  benifit.size(); i++) {
            if (index < 0 && benifit[i] >= 0) {
                index = i;
                value = benifit[i];
            }
            else if (index >= 0) {
                if (value + benifit[i] < 0) {
                    index = -1;
                    value = 0;
                }
                else {
                    value += benifit[i];
                }
            }
        }

        if (index >= 0) {
            for (int i = 0; i < index; i++) {
                value += benifit[i];
            }

            if (value >= 0)
                return index;
        }

        return -1;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Solution s;
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };

    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;
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
