/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int ptr = 0;

    for (auto c : t) {
        if (c == s[ptr]) {
            ptr++;
        }
    }

    return ptr == s.size();
}

int main() {
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";

    cout << isSubsequence(s1, t1) << endl;
    cout << isSubsequence(s2, t2) << endl;
}