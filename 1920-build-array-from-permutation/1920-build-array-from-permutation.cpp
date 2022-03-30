class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int> result(nums.size(), 0);
        result = nums;
        
        for (size_t i = 0; i < nums.size(); i++) {
            result[i] = nums[nums[i]]; 
        }
        
        return result;
    }
};