class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int ans = 0;
        long long pow = 1; 
        
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            ans += (columnTitle[i] - 64) * pow;
            pow *= 26;
        }
        
      return ans;
    }
};