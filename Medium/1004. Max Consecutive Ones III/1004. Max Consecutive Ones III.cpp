/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int longest_sequence = 0;
    int current_sequence = 0;
    int available_swaps = k;
    int index = 0;

    for (auto n : nums) {
        if (n == 1) {
            current_sequence++;
    
            if (current_sequence > longest_sequence) {
                longest_sequence = current_sequence;
            }
        }
        else {
            if (available_swaps != 0) {
                available_swaps--;
                current_sequence++;

                if (current_sequence > longest_sequence) {
                    longest_sequence = current_sequence;
                }
            }
            else {
                while (available_swaps == 0) {
                    if (nums[index] == 1) {
                        index++;
                        current_sequence--;
                    }
                    else {
                        index++;
                        current_sequence--;

                        available_swaps++;
                    }
                }
                current_sequence++;
                available_swaps--;
            }
        }
    }

    return longest_sequence;
}

int main() {
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0},
                nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k1 = 2,
        k2 = 3;

    cout << longestOnes(nums1, k1) << endl;
    cout << longestOnes(nums2, k2) << endl;
}