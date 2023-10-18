class Solution {
public: 
    int helper(const string& s, vector<string>& dict) 
    {
        if (memo.count(s) != 0) {
            return memo[s];
        }

        const size_t DIC_LEN = dict.size();
        int maxi = 0;

        for (size_t i = 0; i < DIC_LEN; i++) {
            size_t b = s.find(dict[i]); // 인덱스 반환
            if (b != string::npos) {
                int a = helper(s.substr(0, b), dict) + helper(s.substr(b + dict[i].size()), dict);
                a += dict[i].size();
                maxi = max(a, maxi);
            }
        }
        memo[s] = maxi; // Store the result in the memoization table

        return maxi;
    }
    
    int minExtraChar(const string& s, vector<string>& dict) 
    {
        const int n = s.size();
        return n - helper(s, dict);
    }

private:
    unordered_map<string, int> memo; // Memoization table
};

// https://leetcode.com/problems/extra-characters-in-a-string/description/
