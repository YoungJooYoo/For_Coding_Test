class Solution {
public:
    int removePalindromeSub(string s) 
    {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return 2;
            }
        }
        
        return 1; 
    }
};