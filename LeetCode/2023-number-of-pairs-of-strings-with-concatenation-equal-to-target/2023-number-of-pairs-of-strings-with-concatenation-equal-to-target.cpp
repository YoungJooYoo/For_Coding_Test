class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans = 0;
        vector<string> nums2 = nums;
        const size_t NUMS_LENGTH = nums.size();
        
        reverse(nums2.begin(), nums2.end());
        
        for (size_t i = 0; i < NUMS_LENGTH - 1; i++) {
            for (size_t j = i + 1; j < NUMS_LENGTH; j++) {
                if (nums[i] + nums[j] == target) {
                    ans++;
                }
                if (nums2[i] + nums2[j] == target) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};