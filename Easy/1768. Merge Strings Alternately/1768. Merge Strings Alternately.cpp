/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
*/

#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string ans = "";

    bool is_word1_shorter = word1.length() < word2.length();

    int i = 0;

    for (i = 0; i < min(word1.length(), word2.length()); i++) {
        ans = ans + word1[i] + word2[i];
    }

    if (is_word1_shorter) ans += word2.substr(i, word2.length() - i);
    else ans += word1.substr(i, word1.length() - i);
    
    return ans;
}

int main() {
    cout << mergeAlternately("abc", "pqr") << endl;
    cout << mergeAlternately("ab", "pqrs") << endl;
    cout << mergeAlternately("abcd", "pq") << endl;
}