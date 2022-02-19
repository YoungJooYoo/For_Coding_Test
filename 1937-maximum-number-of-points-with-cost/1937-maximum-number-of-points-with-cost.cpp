class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        long long ans = 0;
        long long row = points.size();
        long long col = points[0].size();
    
        vector<long long> dp(col, 0);
        
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) { 
                dp[j] += points[i][j];
            }
            for (size_t j = 1; j < col; j++) { 
                dp[j] = max(dp[j], dp[j - 1] - 1); // 왼쪽 값만 체크
            }
            for (int j = col - 2; j >= 0; j--) {
                dp[j] = max(dp[j], dp[j + 1] - 1); // 오른쪽만 체크
            }
            
        }
    
        for (size_t i = 0; i < col; i++) {
            ans = max(ans, dp[i]);
        }
    
        return ans;
    }
};