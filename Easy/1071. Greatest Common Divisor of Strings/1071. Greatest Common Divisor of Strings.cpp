/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/

#include <bits/stdc++.h>
using namespace std;

string repeatString(string str, int n) {
	string ans;
	for (int i = 0; i < n; i++) {
		ans = ans + str;
	}

	return ans;
}

string gcdOfStrings(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();

	vector<int> div1, div2;

	for (int i = 1; i <= len1; i++) {
		if (len1 % i == 0) {
			div1.push_back(i);
		}
	}
	for (int i = 1; i <= len2; i++) {
		if (len2 % i == 0) {
			div2.push_back(i);
		}
	}

	vector<string> div_str1, div_str2;
	for (auto n : div1) {
		string sub_str = str1.substr(0, n);
		if (repeatString(sub_str, len1 / n) == str1) div_str1.push_back(sub_str);
	}
	for (auto n : div2) {
		string sub_str = str2.substr(0, n);
		if (repeatString(sub_str, len2 / n) == str2) div_str2.push_back(sub_str);
	}

	for (int i = div_str1.size() - 1; i >= 0; i--) {
		for (int j = div_str2.size() - 1; j >= 0; j--) {
			if (div_str1[i] == div_str2[j]) {
				return div_str1[i];
			}
		}
	}

	return "";
}

int main() {
	cout << gcdOfStrings("ABCABC", "ABC") << endl;
	cout << gcdOfStrings("ABABAB", "ABAB") << endl;
	cout << gcdOfStrings("LEET", "CODE") << endl;
}