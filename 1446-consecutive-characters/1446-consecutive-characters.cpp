class Solution {
public:
    int maxPower(string s) 
    {
        int max_length = 0;
        int count = 1;
        
        if (s.size() == 1) {
            return 1;
        }
        
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                count++;
            }
            else {
                count = 1;
            }
            max_length = max(max_length, count);
        }
        
        return max_length;
    }
};