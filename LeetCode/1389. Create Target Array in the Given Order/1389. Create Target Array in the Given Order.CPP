class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
        vector<int> result;
        int j = 0;

        for (const auto& off_set : index) {
            auto it = result.begin();
            result.insert(it + off_set, nums[j++]);
        } 
        
        return result;
    }
};
// https://leetcode.com/problems/create-target-array-in-the-given-order/description/
