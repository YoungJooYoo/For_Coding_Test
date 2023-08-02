class Solution {
public:
    int helper(vector<int>& nums, size_t index, int sum)
    {
        if (index == nums.size()) 
        {
            return sum;
        }

        return helper(nums, index + 1, sum ^ nums[index]) + helper(nums, index + 1, sum);
    }

    int subsetXORSum(vector<int>& nums) 
    {
        return helper(nums, 0, 0);
    }
};
