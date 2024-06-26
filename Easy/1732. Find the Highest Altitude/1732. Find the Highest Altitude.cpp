/*
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
*/

#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int max = 0;
    int curr = 0;

    for (auto x : gain) {
        curr += x;
        if (curr > max) {
            max = curr;
        }
    }

    return max;
}

int main() {
    vector<int> gain1 = {-5, 1, 5, 0, -7},
                gain2 = {-4, -3, -2, -1, 4, 3, 2};

    cout << largestAltitude(gain1) << endl;
    cout << largestAltitude(gain2) << endl;
}