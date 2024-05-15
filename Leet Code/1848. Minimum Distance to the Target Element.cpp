class Solution {
public:
    int getMinDistance(const vector<int>& nums, const int target, const int start) 
    {
        const int LENGTH = nums.size();
        int minDistance = INT_MAX;

        for (int i = 0; i < LENGTH; ++i) 
        {
            if (target == nums[i])
            {
                minDistance = min(minDistance, abs(i - start));
            }
        }

        return minDistance;
    }
};

// https://leetcode.com/problems/minimum-distance-to-the-target-element/description/
