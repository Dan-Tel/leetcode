/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> unique_nums;

    for (auto n : nums) {
        if (!unique_nums.insert(n).second) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1},
                nums2 = {1, 2, 3, 4},
                nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << containsDuplicate(nums1) << endl;
    cout << containsDuplicate(nums2) << endl;
    cout << containsDuplicate(nums3) << endl;
}