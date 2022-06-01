class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans = 0;
        const size_t NUMS_LENGTH = nums.size();
        
        for (size_t i = 0; i < NUMS_LENGTH - 1; i++) {
            for (size_t j = i + 1; j < NUMS_LENGTH; j++) {
                if (nums[i] + nums[j] == target) {
                    ans++;
                }
            }
        }
        
        reverse(nums.begin(), nums.end());
        
        for (size_t i = 0; i < NUMS_LENGTH - 1; i++) {
            for (size_t j = i + 1; j < NUMS_LENGTH; j++) {
                if (nums[i] + nums[j] == target) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};