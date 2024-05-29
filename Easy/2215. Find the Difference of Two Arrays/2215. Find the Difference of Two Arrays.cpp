/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
* answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
* answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans = {{}, {}};

    vector<int> colorizer(2001);
    for (auto n : nums1) {
        colorizer[n + 1000] = 1;
    }
    for (auto n : nums2) {
        if (colorizer[n + 1000] == 1 || colorizer[n + 1000] == 3) {
            colorizer[n + 1000] = 3;
        }
        else {
            colorizer[n + 1000] = 2;
        }
    }

    for (int i = 0; i < colorizer.size(); i++) {
        if (colorizer[i] == 1) {
            ans[0].push_back(i - 1000);
        }
        if (colorizer[i] == 2) {
            ans[1].push_back(i - 1000);
        }
    }

    return ans;
}

void printMatrix(vector<vector<int>> m) {
    for (auto r : m) {
        for (auto c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> nums11 = {1, 2, 3}, nums21 = {2, 4, 6},
                nums12 = {1, 2, 3, 3}, nums22 = {1, 1, 2, 2};

    printMatrix(findDifference(nums11, nums21));
    printMatrix(findDifference(nums12, nums22));
}