class Solution {
public:
    string makeGood(string s) 
    {
        /*
        int sz = 0;
        while (sz != s.size()) {
            sz = s.size();
            for (int i = 0; i + 1 < s.size(); ++i) {
                if (abs(s[i] - s[i + 1]) == UPPER) {
                    s = s.substr(0, i) + s.substr(i + 2);
                }
            }     
        } */


        for (int i = 0; i + 1 < s.size(); ++i) {
            if (abs(s[i] - s[i + 1]) == UPPER) {
                return makeGood(s.substr(0, i) + s.substr(i + 2));
            }
        }    
        return s;
    }

private:
    enum { UPPER = 32 };
};

// https://leetcode.com/problems/make-the-string-great/description/
