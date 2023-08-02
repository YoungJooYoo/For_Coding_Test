class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int sum;
        int size = nums.size();
        
        while (size-- != 0) {
            for (size_t i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10; 
            }
        }
        
        return nums[0];
    }
};