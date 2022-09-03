class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size(); 
        int n2 = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  
        // i = 1인 이유, 0시작에서 연관된 값을 그 다음 순서인 i에 누적, 즉 0지나고 현재 1까지 와서 최대 길이 저장
        // i <= n1 이유, 1부터 시작했으므로, 마지막 원소 n1 - 1까지오면, 그 값을 저장해야하는 것은 n1까지다.
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 0;
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};