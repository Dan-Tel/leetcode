/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int rob(vector<int>& nums, int pos = -2) {
    if (memo.empty()) {
        memo = vector<int>(nums.size(), -1);
    }

    if (pos == -2) {
        pos = nums.size() - 1;
    }

    if (pos == -1) {
        return 0;
    }

    if (pos == 0) {
        return nums[0];
    }

    if (memo[pos] != -1) {
        return memo[pos];
    }

    int max_money = max(rob(nums, pos - 2) + nums[pos], rob(nums, pos - 1));
    memo[pos] = max_money;
    return max_money;
}

void init() {
    memo = {};
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1},
                nums2 = {2, 7, 9, 3, 1};

    init();
    cout << rob(nums1) << endl;
    init();
    cout << rob(nums2) << endl;
}