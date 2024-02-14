class Solution {
public:
    bool isCircularSentence(const string& sentence) 
    {
        vector<string> words;
        stringstream sstream(sentence);
        string word;

        while(getline(sstream, word, ' '))
        {
            words.push_back(word);
        }

        for (size_t i = 0; i < words.size() - 1; ++i) {
            if (words[i].back() != words[i + 1].front()) {
                return false;
            }
        }


        return words.front().front() ==  words.back().back() ? true : false;
    }
};

// https://leetcode.com/problems/circular-sentence/description/
