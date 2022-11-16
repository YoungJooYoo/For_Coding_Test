class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int count = 0;
        size_t count_r = 0;
        size_t count_l = 0;
        
        for (const auto& ch : s) {
            if (ch == 'R') {
                count_r++;
            }
            else if (ch == 'L') {
                count_l++;
            }
            if (count_r == count_l) {
                count++;
                count_r = 0;
                count_l = 0;
            }
        }
        
        return count;
    }
};