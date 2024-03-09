class Solution {
public:
    bool validWordSquare(vector<string>& words) 
    {
        const size_t LENGTH = words.size();

        for (size_t i = 0; i < LENGTH; ++i) {
            if (words[i].size() > LENGTH) {
                return false;
            }
            for (size_t j = 0; j < words[i].size(); ++j) {
                if  (words[i][j] !=words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/valid-word-square/description/
