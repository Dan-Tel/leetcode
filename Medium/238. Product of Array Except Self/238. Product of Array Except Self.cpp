/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    long long mult = 1;
    long long mult_2 = 1;
    bool one_zero = false;
    for (auto n : nums) {
        if (n == 0) {
            if (!one_zero) one_zero = true;
            else if (one_zero) mult_2 = 0;
        }
        else {
            mult_2 *= n;
        }
        mult *= n;
    }
    
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            ans[i] = mult_2;
        }
        else {
            ans[i] = mult / nums[i];
        }
    }

    return ans;
}

void printVector(vector<int> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	vector<int> nums1 = {1, 2, 3, 4},
				nums2 = {-1, 1, 0, -3, 3};

	printVector(productExceptSelf(nums1));
	printVector(productExceptSelf(nums2));
}