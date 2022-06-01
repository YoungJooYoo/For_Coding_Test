class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans = 0;
        
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size(); j++) {
                if (i != j and target == nums[i] + nums[j]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};