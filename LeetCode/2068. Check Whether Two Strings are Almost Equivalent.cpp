class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) 
    {   
        unordered_map<int, int> freq;

        for (const auto& ch : word1) {
            freq[ch]++;
        }
        for (const auto& ch : word2) {
            freq[ch]--;
        }

        for (const auto& elem : freq) {
            if (abs(elem.second) >  3) return false;
        }

        return true;
    }
};


// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/
