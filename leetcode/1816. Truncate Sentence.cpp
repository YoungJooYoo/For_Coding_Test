#define SPACE_CHAR (' ')

class Solution {
public:
    string truncateSentence(string s, int k) 
    {
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == SPACE_CHAR && --k == 0) {
                return s.substr(0, i);
            }
        }

        return s;
    }
};


// https://leetcode.com/problems/truncate-sentence/description/
