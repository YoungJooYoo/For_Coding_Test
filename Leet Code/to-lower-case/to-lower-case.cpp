class Solution {
public:
    string toLowerCase(string s) {
        // 'a' = 97, 'A' = 65
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90) {
               s[i] = s[i] + 32;
            }
        }
        return s;
    }
};