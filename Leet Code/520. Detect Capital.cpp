class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool first_capital = isupper(word[0]);
        bool all_capital = true;
        bool all_small = true; 

        for (size_t i = 1; i < word.size(); ++i) {
            if (isupper(word[i])) all_small = false;
            else all_capital = false;
        }

        return (first_capital == true && all_capital == true) || all_small == true; 
    }
};

// https://leetcode.com/problems/detect-capital/description/
