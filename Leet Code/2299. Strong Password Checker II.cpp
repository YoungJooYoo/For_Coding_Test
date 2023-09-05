class Solution {
public:
    bool strongPasswordCheckerII(string p) 
    {
        if(size(p) < PASSWORD_MIN_LENGTH) return false;

        bool low = false;
        bool upper = false;
        bool digit = false;
        bool special = false;

        for (const auto c : p) {
            if (c >= 'a' and c <= 'z') low = true;
            else if(c >= 'A' and c <= 'Z') upper = true;
            else if (isdigit(c)) digit = true;
            else special = true;
        }
        //Check the 6th condition
        for (int i = 0; i + 1 < size(p); ++i) if (p[i] == p[i+1]) return false;
 
        return low and upper and digit and special ? true : false;
    }

private:
    enum {
        LOWERCASE = 0,
        UPPERCASE = 1,
        ONE_DIGIT = 2,
        ONE_SPEICAL_CHARACTER = 3,
        LENGTH = 4,
        PASSWORD_MIN_LENGTH = 8
    };
};

// https://leetcode.com/problems/strong-password-checker-ii/description/
