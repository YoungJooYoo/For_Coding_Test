class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int> ans(2 * nums.size(), 0);
        
        for (size_t i = 0, j = nums.size(); i < nums.size(); i++, j++) {
            ans[i] = ans[j] = nums[i];
        }
        
        return ans;
    }
};