class Solution {
public:
    int countAsterisks(string s) 
    {
        int cnt = 0;
        int bar = 1;

        for (const auto& ch:s){
            if (ch == '|') ++bar; 
            else if (bar % 2 == 1 && ch == '*') cnt++; // odd bar, so cnt++
        }

        return cnt;
    }
};

// https://leetcode.com/problems/count-asterisks/description/
