class Solution {
public:
    bool checkString(const string& s) 
    {
        const size_t STR_LENGTH = s.size();

        for (size_t i = 0; i < STR_LENGTH - 1; ++i) {
            if (s[i] == 'b' && s[i + 1] == 'a') return false;
        }

        return true;
    }
};

// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
