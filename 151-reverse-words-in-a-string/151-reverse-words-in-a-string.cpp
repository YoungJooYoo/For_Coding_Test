class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        int i = 0, j, len = s.size();
        while (true) {
            // advancing i and j indexes around the next word
            while (i < len && s[i] == ' ') i++;
            // exit condition - we are done in case
            if (i >= len) break;
            j = i + 1;
            while (j < len && s[j] != ' ') j++;
            tmp = s.substr(i, j - i);
            res = tmp + (res.size() ? " " : "") + res;
            // moving to the next word
            i = j + 1;
        }
        return res;
    }
};