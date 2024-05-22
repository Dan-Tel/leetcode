/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/

#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    long long min1 = LLONG_MAX;
    long long min2 = LLONG_MAX;
    long long min3 = LLONG_MAX;

    for (auto x : nums) {
        if (x < min1) {
            min1 = x;
        }
        else if (x < min2 && x > min1) {
            min2 = x;
        }
        else if (x < min3 && x > min2 && x > min1) {
            min3 = x;
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5},
                nums2 = {5, 4, 3, 2, 1},
                nums3 = {2, 1, 5, 0, 4, 6};
    
    cout << increasingTriplet(nums1) << endl;
    cout << increasingTriplet(nums2) << endl;
    cout << increasingTriplet(nums3) << endl;
}