class Solution {
public:
    int minimumSwaps(vector<int>& nums) 
    {
        const int MAX = *max_element(nums.begin(), nums.end());
        const int MIN = *min_element(nums.begin(), nums.end());
        int i_min = 0;
        int i_max = nums.size() - 1;

        for(;nums[i_min] != MIN; i_min++);
        for(;nums[i_max] != MAX; i_max--);

        return i_min + ((nums.size() - 1)- i_max) - (i_min > i_max);
    }
};

// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/description/
