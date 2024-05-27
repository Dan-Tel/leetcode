/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }

    if (memo.empty()) {
        memo = vector<int>(n + 1);
    }

    if (memo[n]) {
        return memo[n];
    }

    int tribonacci_sum = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    memo[n] = tribonacci_sum;
    return tribonacci_sum;
}

void init() {
    memo = {};
}

int main() {
    init();
    cout << tribonacci(4) << endl;
    init();
    cout << tribonacci(25) << endl;
}