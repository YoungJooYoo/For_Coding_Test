class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int> result;
        
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result.push_back(i);
            }    
        }
    
        return result;
    }
};