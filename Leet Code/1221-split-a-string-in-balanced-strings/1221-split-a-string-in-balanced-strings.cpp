class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int count = 0;
        size_t flag = 0;
        
        for (const auto& ch : s) {
            if (ch == 'R') {
                flag++;
            }
            else if (ch == 'L') {
                flag--;
            }
            if (flag == 0) {
                count++;
                flag = 0;
            }
        }
        
        return count;
    }
};