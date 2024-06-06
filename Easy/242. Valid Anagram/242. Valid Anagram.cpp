/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    vector<int> occ(123);

    for (auto c : s) {
        occ[(int)c]++;
    }
    for (auto c : t) {
        occ[(int)c]--;
    }

    for (auto n : occ) {
        if (n != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isAnagram("anagram", "nagaram") << endl;
    cout << isAnagram("rat", "car") << endl;
}