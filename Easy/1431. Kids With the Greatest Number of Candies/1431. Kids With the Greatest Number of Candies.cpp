/*
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
	int max_candies = *max_element(candies.begin(), candies.end());

	vector<bool> ans(candies.size());

	for (int i = 0; i < candies.size(); i++) {
		if (candies[i] + extraCandies >= max_candies) {
			ans[i] = true;
		}
	}

	return ans;
}

void printVector(vector<bool> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	vector<int> candies1 = {2, 3, 5, 1, 3},
				candies2 = {4, 2, 1, 1, 2},
				candies3 = {12, 1, 12};

	printVector(kidsWithCandies(candies1, 3));
	printVector(kidsWithCandies(candies2, 1));
	printVector(kidsWithCandies(candies3, 10));
}