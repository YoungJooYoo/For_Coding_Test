class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) 
    {
        const size_t LEN = words.size();
        int count = 0;
        
        for (size_t i = 0; i < LEN; ++i) {
            const string str1 = words[i];
            for (size_t j = i + 1; j < LEN; ++j) {
                const string str2 = words[j];
                if (str1[0] == str2[1] && str1[1] == str2[0]) ++count;
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/
