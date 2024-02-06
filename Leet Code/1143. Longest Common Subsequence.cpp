class Solution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) 
    {
        const int m = text1.size();
        const int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 이전 길이의 최대값과 현재 길이 최대값중 취합
                }
            }
        }

        for (auto row : dp) {
            for (auto col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
        
        return dp[m][n];
    }
};

// https://leetcode.com/problems/longest-common-subsequence/
