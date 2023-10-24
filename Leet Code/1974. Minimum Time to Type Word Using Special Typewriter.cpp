class Solution {
public:
    int minTimeToType(const string& word) 
    {
        int count = word.size(); // total save time = word length
        char point = 'a';
        
        for (const auto& ch : word) {
            count += min(abs(ch - point), ALPHA_LENGTH - abs(point - ch));
            point = ch;
        }
        
        return count;
    }

private:
    enum { ALPHA_LENGTH = 26 };
};

// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
