/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (auto n : nums) {
        ans ^= n;
    }

    return ans;
}

int main() {
    vector<int> nums1 = {2, 2, 1},
                nums2 = {4, 1, 2, 1, 2},
                nums3 = {1};

    cout << singleNumber(nums1) << endl;
    cout << singleNumber(nums2) << endl;
    cout << singleNumber(nums3) << endl;
}