class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        int k = 0;
        vector<int> ans(n);
        vector<int> dp(n + 1, 0);//DP ARRAY FOR STORE COUNT OF ALL ELEMENTS

        for (int i = 0; i < n; i++) {
            if (dp[A[i]] < 0) k++;
            dp[A[i]]++;
            if (dp[B[i] ] > 0) k++;
            dp[B[i]]--;
            ans[i] = k;
        }

        return ans;
    }
};

// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
