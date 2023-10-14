class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        map<int, long> dp;
        int ans = 0;

        sort(arr.begin(),arr.end());

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) { // 약수라면
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MODULO;
                }
            }
            ans = (ans + dp[arr[i]]) % MODULO;
        }

        return ans;
    }

private: 
    enum { MODULO = 1000000000 + 7 };
};

// https://leetcode.com/problems/binary-trees-with-factors/description/
