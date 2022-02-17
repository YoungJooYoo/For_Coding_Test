class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.size() == 0) {
            return 0;
        }
        
        sort(begin(nums), end(nums));
        return nums[0];
    }
};