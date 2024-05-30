/*
Two strings are considered close if you can attain one from the other using the following operations:

* Operation 1: Swap any two existing characters.
  * For example, abcde -> aecdb
* Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
  * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) {
        return false;
    }

    vector<int> occ1(26), occ2(26);
    vector<int> vec1(26), vec2(26);

    for (auto c : word1) {
        vec1[c - 'a']++;
        occ1[c - 'a'] = 1;
    }
    for (auto c : word2) {
        vec2[c - 'a']++;
        occ2[c - 'a'] = 1;
    }

    for (int i = 0; i < occ1.size(); i++) {
        if ((occ1[i] ^ occ2[i])) {
            return false;
        }
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for (int i = vec1.size() - 1; i >= 0; i--) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
        if (!vec1[i] && !vec2[i]) break;
    }

    return true;
}

int main() {
    string word11 = "abc", word21 = "bca",
           word12 = "a", word22 = "aa",
           word13 = "cabbba", word23 = "abbccc";

    cout << closeStrings(word11, word21) << endl;
    cout << closeStrings(word12, word22) << endl;
    cout << closeStrings(word13, word23) << endl;
}