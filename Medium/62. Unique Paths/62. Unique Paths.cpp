/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

#include <bits/stdc++.h>
using namespace std;

int dp(int i, int j, vector<vector<int>>& memo) {
    if (i == 0 && j == 0) {
        memo[0][0] = 1;
    }

    if (memo[i][j]) {
        return memo[i][j];
    }

    int num = 0;
    if (i > 0) {
        num += dp(i - 1, j, memo);
    }
    if (j > 0) {
        num += dp(i, j - 1, memo);
    }

    memo[i][j] = num;
    return memo[i][j];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n));
    return dp(m - 1, n - 1, memo);
}

int main() {
    int m1 = 3, n1 = 7;
    int m2 = 3, n2 = 2;

    cout << uniquePaths(m1, n1) << endl;
    cout << uniquePaths(m2, n2) << endl;
}