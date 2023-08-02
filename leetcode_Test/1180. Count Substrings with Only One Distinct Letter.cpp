class Solution {
public:
    int countLetters(string s) 
    {
        const size_t SIZE = s.size();
        unordered_map<string, int> freq;
        int count = 0;

        for (size_t i = 0; i < SIZE; ++i) {
            string temp;
            for (size_t j = i; j < SIZE; ++j) {
                if (s[i] == s[j]) {
                    temp += s[j];
                    freq[temp]++;
                }
                else {
                    break;
                }
            }
        }

        for (const auto& cnt : freq) {
            count += cnt.second;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/description/
