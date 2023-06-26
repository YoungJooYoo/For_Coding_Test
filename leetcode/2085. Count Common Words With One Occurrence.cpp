class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        unordered_map<string, int> freq_word1;
        unordered_map<string, int> freq_word2;
        int result = 0;

        for (const auto& word : words1) {
            freq_word1[word]++;

        }
        for (const auto& word : words2) {
            freq_word2[word]++;
        }

        for (const auto& word : freq_word1) {
            if (word.second == 1 && freq_word2[word.first] == 1) ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/count-common-words-with-one-occurrence/description/
