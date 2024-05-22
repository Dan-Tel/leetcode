/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int ptr = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[ptr]);
            ptr++;
        }
    }
}

void printVector(vector<int>& v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
    vector<int> nums1 = {0, 1, 0, 3, 12},
                nums2 = {0};

    moveZeroes(nums1);
    moveZeroes(nums2);

    printVector(nums1);
    printVector(nums2);
}