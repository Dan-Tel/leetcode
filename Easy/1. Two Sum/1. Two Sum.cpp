/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        if (umap.count(target - nums[i])) {
            return {i, umap[target - nums[i]]};
        }
        
        umap[nums[i]] = i;
    }
    return {-1, -1};
}

void printVector(vector<int> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15},
                nums2 = {3, 2, 4},
                nums3 = {3, 3};
    int target1 = 9, target2 = 6, target3 = 6;

    printVector(twoSum(nums1, target1));
    printVector(twoSum(nums2, target2));
    printVector(twoSum(nums3, target3));
}