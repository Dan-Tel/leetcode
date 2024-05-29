/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> occurrences;
    map<int, int> unique_occurrences;

    for (auto n : arr) {
        occurrences[n]++;
    }

    for (auto e : occurrences) {
        if (unique_occurrences[e.second]) {
            return false;
        }

        unique_occurrences[e.second]++;
    }

    return true;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 1, 1, 3},
                arr2 = {1, 2},
                arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    cout << uniqueOccurrences(arr1) << endl;
    cout << uniqueOccurrences(arr2) << endl;
    cout << uniqueOccurrences(arr3) << endl;
}