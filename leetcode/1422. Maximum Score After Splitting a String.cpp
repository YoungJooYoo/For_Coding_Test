class Solution {
public:
    int maxScore(string s) 
    {
        size_t left_zeros = 0;
        size_t right_ones = 0;
        size_t max_score = 0;

        for (const char& ch : s) {
            if (ch == '1') ++right_ones;
        }

        for (size_t i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') ++left_zeros;
            else --right_ones;
            max_score = max(max_score, left_zeros + right_ones);
        }

        return max_score;
    }
};

// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
