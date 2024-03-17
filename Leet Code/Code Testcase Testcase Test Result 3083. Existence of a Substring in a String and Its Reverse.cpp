class Solution {
public:
    bool isSubstringPresent(const string& s) 
    {
        string rerversed_s = s;
        reverse(rerversed_s.begin(), rerversed_s.end());
        const size_t STR_LENGTH = s.size();

        for (size_t i = 0;  i < STR_LENGTH - 1; ++i) {
            if (rerversed_s.find(s.substr(i, 2)) != string::npos) {
                return  true;
            }
        }

        return false;
    }  
};

// https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/
