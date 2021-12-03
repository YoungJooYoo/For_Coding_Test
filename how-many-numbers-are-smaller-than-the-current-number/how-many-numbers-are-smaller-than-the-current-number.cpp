class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const size_t nums_length = nums.size();
        vector<int> ans;
        int count = 0;
        
        for (size_t i = 0; i < nums_length; i++) {
            for (size_t j = 0; j < nums_length; j++) {
                if (nums[i] > nums[j]) {
                    count++;
                }    
            }
            ans.push_back(count);
            count = 0;
        }
        
        return ans;
    }
};