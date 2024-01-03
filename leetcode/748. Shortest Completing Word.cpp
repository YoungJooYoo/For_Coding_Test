class Solution {
public:
    string mostCommonWord(const string& paragraph, const vector<string>& banned) 
    {
        unordered_map<string, int> freq;
        string result;
        const size_t LEN = paragraph.size();
        size_t i = 0;

        while (i < LEN) {
            string temp;
            while (i < LEN && isalpha(paragraph[i])) {
                temp.push_back(tolower(paragraph[i++]));
            }            
            while (i < LEN && !isalpha(paragraph[i])) {
                ++i;
            }
            bool b_is_banned = false;
            for (const auto& elem : banned){
                if (temp == elem) {
                    b_is_banned = true;
                }
            }
            if (b_is_banned == false) ++freq[temp];   
        }

        int max_freq = 0;
        for (const auto& elem : freq) {
            if (elem.second > max_freq) {
                max_freq = elem.second;
                result = elem.first;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/shortest-completing-word/
