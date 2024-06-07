/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> umap;
    vector<vector<string>> ans;
    int current_index = 0;
    
    for (auto s : strs) {
        string key = string(26, ' ');

        for (auto c : s) {
            int index = (int)c - 97;
            key[index]++;
        }

        if (!umap.count(key)) {
            umap[key] = current_index;
            current_index++;
            ans.push_back({});
        }
        
        ans[umap[key]].push_back(s);
    }

    return ans;
}

void printVector(vector<vector<string>> v) {
	for (auto y : v) {
		for (auto x : y) {
            cout << x << " ";
        }
        cout << endl;
	}
	cout << endl;
}

int main() {
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"},
                   strs2 = {""},
                   strs3 = {"a"};

    printVector(groupAnagrams(strs1));
    printVector(groupAnagrams(strs2));
    printVector(groupAnagrams(strs3));
}