/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
*/

#include <bits/stdc++.h>
using namespace std;

double maxVowels(string s, int k) {
    int vow = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a' ||
            s[i] == 'e' ||
            s[i] == 'i' ||
            s[i] == 'o' ||
            s[i] == 'u') {
                vow++;
            }
    }
    int max_vow = vow;

    for (int i = k; i < s.length(); i++) {
        if (s[i] == 'a' ||
            s[i] == 'e' ||
            s[i] == 'i' ||
            s[i] == 'o' ||
            s[i] == 'u') {
                vow++;
            }
        if (s[i - k] == 'a' ||
            s[i - k] == 'e' ||
            s[i - k] == 'i' ||
            s[i - k] == 'o' ||
            s[i - k] == 'u') {
                vow--;
            }
        
        if (vow > max_vow) max_vow = vow;
    }

    return max_vow;
}

int main() {
    string s1 = "abciiidef", s2 = "aeiou", s3 = "leetcode";
    int k1 = 3, k2 = 2, k3 = 3;

    cout << maxVowels(s1, k1) << endl;
    cout << maxVowels(s2, k2) << endl;
    cout << maxVowels(s3, k3) << endl;
}