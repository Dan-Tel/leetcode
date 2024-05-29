/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int longest_sequence = 0;
    int current_sequence = 0;
    bool can_delete = true;
    int index = 0;

    for (auto n : nums) {
        if (n == 1) {
            current_sequence++;

            if (current_sequence > longest_sequence) {
                longest_sequence = current_sequence;
            }
        }
        else {
            if (can_delete) {
                can_delete = false;
                continue;
            }
            else {
                while (!can_delete) {
                    if (nums[index] == 1) {
                        index++;
                        current_sequence--;
                    }
                    else {
                        index++;
                        break;
                    }
                }
            }
        }
    }

    if (can_delete) {
        return longest_sequence - 1;
    }
    else {
        return longest_sequence;
    }
}

int main() {
    vector<int> nums1 = {1, 1, 0, 1},
                nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1},
                nums3 = {1, 1, 1};
    
    cout << longestSubarray(nums1) << endl;
    cout << longestSubarray(nums2) << endl;
    cout << longestSubarray(nums3) << endl;
}