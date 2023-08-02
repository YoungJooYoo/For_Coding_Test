class Solution {
public:
    bool is_prefix(const string& word, const string& s)
    {  
        // word의 길이만큼 인덱스 위치로 서로 비교.
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] != s[i]) return false;
        }

        return true;
    }

    int countPrefixes(const vector<string>& words, const string s) 
    {
        int result = 0;
        
        for (const auto& word : words) {
            if (is_prefix(word, s) == true) ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/count-prefixes-of-a-given-string/description/
