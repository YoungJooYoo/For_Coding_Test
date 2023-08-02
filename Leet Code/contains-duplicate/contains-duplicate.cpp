class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        const size_t nums_length = nums.size();
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums_length - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }   
        }
        
        return false;
    }
};