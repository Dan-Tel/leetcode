/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    
    for (auto a : asteroids) {
        if (ans.empty()) {
            ans.push_back(a);
        }
        else {
            int last = *(ans.end() - 1);
            if (a > 0) {
                ans.push_back(a);
            }
            else {
                while (last < abs(a) && last > 0) {
                    ans.pop_back();
                    if (ans.empty()) {
                        break;
                    }
                    last = *(ans.end() - 1);
                }

                if (!ans.empty()) {
                    if (last == abs(a)) {
                        ans.pop_back();
                    }
                    else if (last < 0) {
                        ans.push_back(a);
                    }
                }
                else {
                    ans.push_back(a);
                }
            }
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
    vector<int> asteroids1 = {5, 10, -5},
                asteroids2 = {8, -8},
                asteroids3 = {10, 2, -5};

    printVector(asteroidCollision(asteroids1));
    printVector(asteroidCollision(asteroids2));
    printVector(asteroidCollision(asteroids3));
}