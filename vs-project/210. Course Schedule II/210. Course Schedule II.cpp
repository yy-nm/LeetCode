// 210. Course Schedule II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {

    // 再加一个函数表示， 依赖 index, 然后进行判断
    bool canLearn(int index, int index_dep, std::vector<int>& learned, std::vector<bool>& dep, std::vector<int>& dep_in_push, const vector<vector<bool>>& pre, const vector<bool>& has, int& count, bool startNew) {

        if (dep[index]) {
            //if (index_dep >= 0 && dep[index_dep] < dep[index])
            //    return true;
            return false;
        }

        if (learned[index] >= 0)
            return true;

        if (!has[index]) {
            dep[index] = true;
            dep_in_push.push_back(index);
            return true;
        }

        dep[index] = true;
        dep_in_push.push_back(index);

        for (int i = 0; i < pre[index].size(); i++) {
            if (pre[index][i]) {
                //if (startNew) 
                {
                    std::vector<bool> depNew(dep);
                    std::vector<int> depPush;
                    //int oldCount = count;
                    if (!canLearn(i, index, learned, depNew, depPush, pre, has, count, false))
                        return false;

                    //if (oldCount != count) 
                    {
                        for (const auto& it : depPush) {
                            if (learned[it] == -1) {
                                //dep[it] = oldCount++;
                                //learned[it] = oldCount++;
                                learned[it] = count++;
                            }
                        }

                        //count = oldCount;
                    }
                }
                //else {
                //    if (!canLearn(i, index, learned, dep, dep_in_push, pre, has, count, false))
                //        return false;
                //}
            }
        }

        if (learned[index] == -1) {
            learned[index] = count++;
        }

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<bool>> depMap(numCourses, vector<bool>(numCourses, false));
        vector<bool> depHas(numCourses, false);

        for (const auto& it : prerequisites) {
            depHas[it[0]] = true;
            for (int i = 1; i < it.size(); i++) {
                depMap[it[0]][it[i]] = true;
            }
        }

        std::vector<int> learned(numCourses, -1);

        int count = 0;
        int oldCount = 0;
        std::vector<int> depPush;
        for (int i = 0; i < numCourses; i++) {
            if (learned[i] >= 0) {
                continue;
            }
            else {
                std::vector<bool> dep(numCourses, false);
                oldCount = count;
                if (!canLearn(i, -1, learned, dep, depPush, depMap, depHas, count, true)) {
                    return {};
                }

                //for (int j = 0; j < numCourses; j++) {
                //    if (dep[j] >= 0) {
                //        learned[j] = count - 1 - dep[j] + oldCount;
                //    }
                //}

                //learned[i] = count++;

                if (learned[i] == -1) {
                    learned[i] = count++;
                }
            }
        }

        vector<int> result(numCourses, -1);
        for (int i = 0; i < numCourses; i++) {
            if (learned[i] >= 0) {
                result[learned[i]] = i;
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
