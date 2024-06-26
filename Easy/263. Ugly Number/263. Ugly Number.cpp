/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.
*/

#include <bits/stdc++.h>
using namespace std; 

bool isUgly(int n) {
    if (n == 0) return false;

    while (n % 5 == 0) n /= 5;
    while (n % 3 == 0) n /= 3;
    while (n % 2 == 0) n /= 2;

    return n == 1;
}

int main() {
    cout << isUgly(6) << endl;
    cout << isUgly(1) << endl;
    cout << isUgly(14) << endl;
}