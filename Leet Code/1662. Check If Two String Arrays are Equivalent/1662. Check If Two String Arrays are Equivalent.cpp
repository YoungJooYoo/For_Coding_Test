class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string str1;
        for (const auto& word : word1) {
            str1 += word;
        }

        string str2;
        for (const auto& word : word2) {
            str2 += word;
        }

        return str1 == str2 ? true : false;
    }
};

// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
