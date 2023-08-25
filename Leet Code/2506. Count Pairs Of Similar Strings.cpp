class Solution {
public:
    int similarPairs(vector<string>& words) 
    {
        const size_t LEN = words.size();
        int count = 0;

        for (size_t i = 0; i < LEN; ++i) {
            set<char> curr_word(words[i].begin(), words[i].end());
            for (size_t j = i + 1; j < LEN; ++j) {
                set<char> next_word(words[j].begin(), words[j].end());
                if (curr_word == next_word) ++count;
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/count-pairs-of-similar-strings/description/
