/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int ptr = 0;
    char curr = chars[0];
    int counter = 0;
    for (int i = 0; i < chars.size(); i++) {
        if (chars[i] == curr) {
            counter++;
        }
        else {
            chars[ptr] = curr;
            if (counter > 1) {
                string counter_str = to_string(counter);
                for (auto c : counter_str) {
                    chars[ptr + 1] = c;
                    ptr++;
                }
            }
            curr = chars[i];
            counter = 1;

            ptr++;
        }
    }

    chars[ptr] = curr;
    if (counter > 1) {
        string counter_str = to_string(counter);
        for (auto c : counter_str) {
            chars[ptr + 1] = c;
            ptr++;
        }
    }

    chars = {chars.begin(), chars.begin() + ptr + 1};

    return ptr + 1;
}

void printVector(vector<char> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
    vector<char> chars1 = {'a','a','b','b','c','c','c'},
                chars2 = {'a'},
                chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};

    cout << compress(chars1) << endl;
    cout << compress(chars2) << endl;
    cout << compress(chars3) << endl;

    printVector(chars1);
    printVector(chars2);
    printVector(chars3);
}