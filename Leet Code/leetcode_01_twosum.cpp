class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        
        for(size_t i = 0; i < nums.size(); i++)
        {
            for(size_t j = i + 1; j <= nums.size() - 1; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
        
        return output;
    }
};
