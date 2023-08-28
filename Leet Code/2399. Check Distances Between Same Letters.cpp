class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        const size_t LEN = s.size();

        for (size_t i = 0; i < LEN; ++i) {
            for (size_t j = i + 1; j < LEN; ++j) {
                if (s[i] == s[j] and j - i - 1 != distance[s[i] - 'a']) {
                    return false;
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/check-distances-between-same-letters/description/
