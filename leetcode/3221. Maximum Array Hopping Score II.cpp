class Solution {
public:
    long long maxScore(vector<int>& nums) 
    {
        map<int, int, greater<int>> valueIndexMap;
        const int n = nums.size();

        for (int i = 0; i < n; ++i) 
        {
            valueIndexMap[nums[i]] = i;
        }
        
        int currentIndex = 0;
        long long maxScore = 0;

        for (const auto& [value, index] : valueIndexMap) 
        {
            if (index > currentIndex) 
            {
                maxScore += static_cast<long long>(value) * (index - currentIndex);
                currentIndex = index;
            }
        }

        return maxScore;
    }
};

// 3221. Maximum Array Hopping Score II

// https://leetcode.com/problems/maximum-array-hopping-score-ii/
