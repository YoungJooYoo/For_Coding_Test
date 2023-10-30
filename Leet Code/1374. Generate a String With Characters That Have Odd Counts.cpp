class Solution {
public:
    string generateTheString(int n) 
    {
        return (n % 2 == 1) ? string(n, 'a') : string(n - 1, 'a') + 'b';
    }
};

// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/
