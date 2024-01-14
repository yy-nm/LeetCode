// 18. 4Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int>& nums_new = nums;

        sort(nums_new.begin(), nums_new.end());

        for (int i = 0; i < (int)nums_new.size() - 3; i++) {
            if (i > 0 && nums_new[i] == nums_new[i - 1]) {
                continue;
            }

            if (nums_new[i] > target && target > 0) {
                break;
            }
            if (target < 0 && nums_new[i] > 0) {
                break;
            }

            for (int l = i + 1; l < (int)nums_new.size() - 2; l++) {

                if (l > i + 1 && nums_new[l] == nums_new[l - 1]) {
                    continue;
                }

                if (nums_new[l] + nums_new[i] > target && target > 0) {
                    break;
                }
                if (target < 0 && nums_new[l] + nums_new[i] > 0) {
                    break;
                }

                int j = l + 1;
                int k = nums_new.size() - 1;

                while (j < k) {
                    int64_t v = (int64_t)nums_new[i] + nums_new[l] + nums_new[j] + nums_new[k];
                    if (v == target) {
                        result.push_back({ nums_new[i], nums_new[l], nums_new[j], nums_new[k] });
                        k--;
                        j++;

                        while (j < k && nums_new[k] == nums_new[k + 1]) {
                            k--;
                        }
                        while (j < k && nums_new[j] == nums_new[j - 1]) {
                            j++;
                        }
                    }
                    else if (v > target) {
                        k--;
                        while (j < k && nums_new[k] == nums_new[k + 1]) {
                            k--;
                        }
                    }
                    else {
                        j++;
                        while (j < k && nums_new[j] == nums_new[j - 1]) {
                            j++;
                        }
                    }
                }
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
