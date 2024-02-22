class Solution {
public:
    int findJudge(const int n, const vector<vector<int>>& trust) 
    {
        vector<int> trustCounts(n + 1, 0);
        vector<int> trustedCounts(n + 1, 0);

        for (const auto& relation : trust) {
            const int trust_relation = relation[0];
            const int trusted_relation = relation[1];
            ++trustCounts[trust_relation];
            ++trustedCounts[trusted_relation];
        }

        for  (size_t  i = 0; i <= n; ++i) {
            if (trustCounts[i] == 0 && trustedCounts[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

//  https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22
