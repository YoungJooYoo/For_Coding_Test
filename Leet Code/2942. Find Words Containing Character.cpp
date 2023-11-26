class Solution {
public:
    vector<int> findWordsContaining(const vector<string>& words, const char x) 
    {
        // words  배열에 x가 나오는지 판단
        vector<int> result;

        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos) result.push_back(i);
        }

        return result;
    }
};

// https://leetcode.com/problems/find-words-containing-character/description/
