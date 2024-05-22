/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
    for (int i = 0, j = s.length() - 1; i < j;) {
        bool l_vow = false, r_vow = false;
        if (tolower(s[i]) == 'a' ||
            tolower(s[i]) == 'e' ||
            tolower(s[i]) == 'i' ||
            tolower(s[i]) == 'o' ||
            tolower(s[i]) == 'u') {
                l_vow = true;
            }
        if (tolower(s[j]) == 'a' ||
            tolower(s[j]) == 'e' ||
            tolower(s[j]) == 'i' ||
            tolower(s[j]) == 'o' ||
            tolower(s[j]) == 'u') {
                r_vow = true;
            }

        if (l_vow && r_vow) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if (l_vow) {
            j--;
        }
        else if (r_vow) {
            i++;
        }
        else {
            i++;
            j--;
        }
    }

    return s;
}

int main() {
    cout << reverseVowels("hello") << endl;
    cout << reverseVowels("leetcode") << endl;
}