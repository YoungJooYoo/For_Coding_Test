
class Solution {
public:
    string reverseWords(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        vector<pair<string, int>> words; // word - vowelCount
        stringstream ss(s);
        string temp;

        while (ss >> temp) 
        {
            int vowelCount = 0;
            for (const char c : temp) 
            {
                assert('a' <= c && c <= 'z');
                if (isVowel(c) == true) 
                {
                    ++vowelCount;
                }
            }
            words.push_back({temp, vowelCount});
        }

        if (words.empty())
        {
            return "";
        } 

        int targetVowelCount = words[0].second;
        string result = words[0].first; 
        for (int i = 1; i < words.size(); ++i) 
        {
            string currentWord = words[i].first;
            if (words[i].second == targetVowelCount) 
            {
                ranges::reverse(currentWord);
            }
            result += " " + currentWord;
        }

        return result;
    }

private:
    bool isVowel(char c) const
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
    }

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000
    };
};

// https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/
