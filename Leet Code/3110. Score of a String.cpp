class Solution {
public:
    int scoreOfString(const string& s) 
    {
        const size_t STR_LENGTH = s.size();
        int sum = 0;

        for (size_t i = 0; i < STR_LENGTH - 1; ++i) {
            sum += abs((s[i] - 'a') - (s[i + 1] - 'a'));
        }

        return sum;
    }
};

// https://leetcode.com/problems/score-of-a-string/
