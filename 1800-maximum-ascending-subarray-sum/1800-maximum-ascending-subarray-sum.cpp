class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int result = 0;
        int sum = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] >= nums[i]) {
                result = max(result, sum);
                sum = 0;
            }
            sum += nums[i];
        }
        
        return max(result, sum);
    }
};