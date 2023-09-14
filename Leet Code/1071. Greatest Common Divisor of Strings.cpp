class Solution {
public:
    string gcdOfStrings(const string const str1, const string const str2) 
    {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        const int gcdLength = gcd(str1.size(), str2.size());
        
        return str1.substr(0, gcdLength);
    }
};

// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
