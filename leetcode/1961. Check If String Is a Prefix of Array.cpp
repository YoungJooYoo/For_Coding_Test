class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        string result;
        
        for (const auto& word : words) {
            result += word;
            if (result == s) return true;
        }

        return false;
    }
};

// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/
