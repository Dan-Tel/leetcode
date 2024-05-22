/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> flowerbed, int n) {
    if (n == 0) return true;

    for (int i = 0; i < flowerbed.size(); i++) {
        bool is_ok = true;
        if (flowerbed[i] != 0) {
            is_ok = false;
        }
        if (i > 0) {
            if (flowerbed[i - 1] != 0) {
                is_ok = false;
            }
        }
        if (i < flowerbed.size() - 1) {
            if (flowerbed[i + 1] != 0) {
                is_ok = false;
            }
        }

        if (is_ok) {
            flowerbed[i] = 1;
            n--;
        }

        if (n == 0) return true;
    }

    return false;
}

int main() {
    cout << canPlaceFlowers({1,0,0,0,1}, 1) << endl;
    cout << canPlaceFlowers({1,0,0,0,1}, 2) << endl;
}