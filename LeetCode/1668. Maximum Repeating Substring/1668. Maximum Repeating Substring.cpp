class Solution {
public:
    int maxRepeating(string sequence, string word) 
    {
        auto temp = word;
        int count = 0;

        while (sequence.find(temp) != string::npos) {
            temp += word;
            ++count;
        }

        return count;    
    }
};

// https://leetcode.com/problems/maximum-repeating-substring/description/
