class Solution {
public:
    bool isAcronym(vector<string>& words, string s) 
    {
        string result = "";

        for (const auto&  word : words) {
            result += word[0];
        }

        return result == s ? true : false;
    }
};

// https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/
