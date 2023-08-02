class Solution {
public:
    int firstUniqChar(string s) {
        int alphabet[26] = {0,};
        
        for (size_t i = 0; i < s.size(); i++) {
            alphabet[s[i] - 'a']++;
        }
        
        for (size_t i = 0; i < s.size(); i++) {
            if (alphabet[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};