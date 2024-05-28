/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans = {0, 1};

    if (n == 0) {
        return {0};
    }

    for (int i = 1; true; i++) {
        
        vector<int> sub_ans = {ans.end() - pow(2, i - 1), ans.end()};
        for (auto x : sub_ans) {
            if (ans.size() == n + 1) {
                return ans;
            }
            ans.push_back(x);
        }
        for (auto x : sub_ans) {
            if (ans.size() == n + 1) {
                return ans;
            }
            ans.push_back(x + 1);
        }
    }

    return ans;
}

void printVector(vector<int> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
    printVector(countBits(2));
    printVector(countBits(5));
}