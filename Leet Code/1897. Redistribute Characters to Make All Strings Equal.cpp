class Solution {
public:
    bool makeEqual(const vector<string>& words) 
    {
        unordered_map<char, int> freq;

        for (const auto& word : words) {
            for (const auto& ch : word) {
                ++freq[ch];
            }
        }

        const int WORDS_LENGTH = words.size();
        for (const auto& elem : freq) {
            if (elem.second % WORDS_LENGTH != 0) {
                return false;
            }
        }

        return true; 
    }
};

// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/
