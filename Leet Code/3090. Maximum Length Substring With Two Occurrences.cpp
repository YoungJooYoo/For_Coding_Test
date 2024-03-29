class Solution {
public:
    int maximumLengthSubstring(const string& s) 
    {
        const size_t STR_LENGTH = s.size();
        int max_length = 0;
        
        for (size_t i = 0; i < STR_LENGTH; ++i) {
            unordered_map<char, int> freq;
            for (size_t j = i; j < STR_LENGTH; ++j) {
                if (++freq[s[j]] > 2) {
                    break;
                }
                const int curr_length = j - i + 1;
                max_length = max(max_length, curr_length);
            }
        }

        return max_length; 
    }
};

// https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
