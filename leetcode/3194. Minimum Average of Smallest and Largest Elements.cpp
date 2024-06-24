class Solution 
{
public:
    double minimumAverage(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        double minAVG = DBL_MAX;

        while (i < j)
        {
            const double AVG = (nums[i] + nums[j]) / 2.0;
            minAVG = min(minAVG, AVG);
            ++i;
            --j;
        }

        return minAVG;
    }
};

// https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/
