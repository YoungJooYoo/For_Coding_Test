class Solution {
public:
    int countKeyChanges(string& s) 
    {
        const size_t LEN = s.size();
        int result = 0;

        // 모든 문자를 소문자로 변경
        for (auto& ch : s) {
            ch = tolower(ch);
        }

        for (size_t i = 1; i < LEN; ++i) {
            if (s[i - 1] != s[i]) ++result;
        }

        return result;;
    }
};

// https://leetcode.com/problems/number-of-changing-keys/
