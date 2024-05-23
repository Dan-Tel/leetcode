/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
*/

#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    string ans;
    for (auto c : s) {
        if (c == '*') {
            ans.pop_back();
        }
        else {
            ans += c;
        }
    }
    return ans;
}

int main() {
    string s1 = "leet**cod*e";
    string s2 = "erase*****";

    cout << removeStars(s1) << endl;
    cout << removeStars(s2) << endl;
}