class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const size_t nums_length = nums.size();
        
        if (nums_length == 0) {
            return 0;
        }
        if (nums_length == 1) {
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums_length; i++) {
            if(nums[i] != nums[i + 1]) {
                return nums[i];
            }
            else {
                i++;
            }
        }
        return 0;
    }
};