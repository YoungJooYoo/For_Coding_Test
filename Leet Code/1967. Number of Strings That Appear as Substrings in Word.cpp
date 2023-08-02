class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) 
    {
        int count = 0;
        for (const auto& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/
