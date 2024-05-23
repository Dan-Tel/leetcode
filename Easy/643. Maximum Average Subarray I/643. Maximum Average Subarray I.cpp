/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
*/

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double k_sum = 0;
    for (int i = 0; i < k; i++) {
        k_sum += nums[i];
    }

    double max = k_sum / k;

    for (int i = k; i < nums.size(); i++) {
        k_sum += nums[i] - nums[i - k];
        if (k_sum / k > max) {
            max = k_sum / k;
        }
    }

    return max;
}

int main() {
    vector<int> nums1 = {1,12,-5,-6,50,3};
    vector<int> nums2 = {5};
    int k1 = 4;
    int k2 = 1;

    cout << findMaxAverage(nums1, k1) << endl;
    cout << findMaxAverage(nums2, k2) << endl;
}