class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        const size_t WORD1_SIZE = word1.size();
        const size_t WORD2_SIZE = word2.size();
        string result;

        size_t i  = 0;
        size_t j  = 0;
        while (i < WORD1_SIZE || j < WORD2_SIZE) {
            if (i < WORD1_SIZE) result += word1[i++];
            if (j < WORD2_SIZE) result += word2[j++];
        }

        return result;
    }
};

// https://leetcode.com/problems/merge-strings-alternately/description/
