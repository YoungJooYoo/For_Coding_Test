class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        size_t j = 1;
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[j]) {
                return nums[i];
            }
            j++;
        }
        
        return -1;
    }
};
