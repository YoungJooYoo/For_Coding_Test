class Solution {
public:
    bool checkOnesSegment(const string& s) const
    {
        const uint64_t LENGTH = s.size();

        for (uint32_t i = 1; i < LENGTH; ++i)
        {
            if (s[i - 1] == '0' && s[i] == '1') return false;
        }

        return true;
    }
};

// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
