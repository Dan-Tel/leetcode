/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:
* A word is defined as a character sequence consisting of non-space characters only.
* Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
* The input array words contains at least one word.
*/

#include <bits/stdc++.h>
using namespace std;

string makeLine(vector<string> words, int maxWidth) {
    string ans = "";
    int total_gap_len = maxWidth;

    for (auto w : words) {
        total_gap_len -= w.length();
    }
    
    int division_num = words.size() - 1;

    if (division_num == 0) {
        return words[0] + string(total_gap_len, ' ');
    }

    for (int i = 0; i < words.size() - 1; i++) {
        ans += words[i];
        string gap = string(ceil((float)total_gap_len / (float)division_num), ' ');
        ans += gap;

        total_gap_len -= gap.length();
        division_num--;   
    }
    ans += words[words.size() - 1];

    return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    vector<string> current_line;
    int line_len = 0;

    for (auto w : words) {
        if (line_len + w.size() > maxWidth) {
            ans.push_back(makeLine(current_line, maxWidth));
            current_line = {w};
            line_len = w.size() + 1;
        }
        else {
            line_len += w.size() + 1;
            current_line.push_back(w);
        }
    }

    string last_line = "";
    for (int i = 0; i < current_line.size(); i++) {
        last_line += current_line[i];
    
        if (i != current_line.size() - 1) {
            last_line += " ";
        }
    }

    last_line += string(maxWidth - line_len + 1, ' ');
    ans.push_back(last_line);

    return ans;
}

void printVector(vector<string> v) {
	for (auto x : v) {
		cout << x << "\n";
	}
	cout << endl;
}

int main() {
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."},
                   words2 = {"What","must","be","acknowledgment","shall","be"},
                   words3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth1 = 16,
        maxWidth2 = 16,
        maxWidth3 = 20;

    printVector(fullJustify(words1, maxWidth1));
    printVector(fullJustify(words2, maxWidth2));
    printVector(fullJustify(words3, maxWidth3));
}