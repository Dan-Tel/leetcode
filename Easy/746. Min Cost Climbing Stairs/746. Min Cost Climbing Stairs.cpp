/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int minCostClimbingStairs(vector<int>& cost, int pos = -1) {
    if (memo.empty()) {
        memo = vector<int>(cost.size() + 1, -1);
    }

    if (pos == -1) {
        pos = cost.size();
    }

    if (pos == 0 || pos == 1) {
        return cost[pos];
    }

    if (memo[pos] != -1) {
        return memo[pos];
    }

    int min_cost = min(minCostClimbingStairs(cost, pos - 1), minCostClimbingStairs(cost, pos - 2)) + (pos != cost.size() ? cost[pos] : 0);
    memo[pos] = min_cost;
    return min_cost;
}

void init() {
    memo = {};
}

int main() {
    vector<int> cost1 = {10, 15, 20},
                cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    init();
    cout << minCostClimbingStairs(cost1) << endl;
    init();
    cout << minCostClimbingStairs(cost2) << endl;
}