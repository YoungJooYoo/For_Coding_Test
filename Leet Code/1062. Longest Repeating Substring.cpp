class Solution {
public:
    int longestRepeatingSubstring(const string& s) 
    {
        
        const int n = s.size(); // The problem is approached using the Longest Common Substring (LCS) pattern
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));  // dp table to store lengths of repeating substrings
        int maxLength = 0; // To keep track of the maximum length found

        // In LCS, there's a concept of index shift, hence starting from 1
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) { // Ensure j < i to avoid comparing the character with itself
                if (s[i - 1] == s[j - 1]) {
                    // If characters match, extend the length of the common substring
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // Update maxLength if a longer repeating substring is found
                    maxLength = max(maxLength, dp[i][j]);
                }
                // No need for an else clause; if characters don't match, the default value is 0
            }
        }

        return maxLength; // Return the length of the longest repeating substring
    }
};

// https://leetcode.com/problems/longest-repeating-substring/description/
