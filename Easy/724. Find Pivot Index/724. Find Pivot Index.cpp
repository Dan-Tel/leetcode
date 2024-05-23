/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    vector<int> pref(nums.size() + 2), suff(nums.size() + 2);

    for (int i = 0, j = nums.size() - 1; i < nums.size(), j >= 0; i++, j--) {
        pref[i + 1] = pref[i] + nums[i];
        suff[j + 1] = suff[j + 2] + nums[j];
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (pref[i - 1] == suff[i + 1]) {
            return i - 1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums1 = {1, 7, 3, 6, 5, 6},
                nums2 = {1, 2, 3},
                nums3 = {2, 1, -1};

    cout << pivotIndex(nums1) << endl;
    cout << pivotIndex(nums2) << endl;
    cout << pivotIndex(nums3) << endl;
}