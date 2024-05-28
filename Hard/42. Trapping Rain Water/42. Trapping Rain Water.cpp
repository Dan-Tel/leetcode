/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int max = 0;
    for (auto h : height) {
        if (h > max) {
            max = h;
        }
    }

    int water = max * height.size();
    int max_i = 0, max_j = 0;
    
    for (int i = 0, j = height.size() - 1; i < height.size(), j >= 0; i++, j--) {
        if (height[i] > max_i) {
            max_i = height[i];
        }
        if (height[j] > max_j) {
            max_j = height[j];
        }

        water -= (max - max_i + max - max_j + height[i]);
    }

    return water;
}

int main() {
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1},
                height2 = {4,2,0,3,2,5};

    cout << trap(height1) << endl;
    cout << trap(height2) << endl;
}