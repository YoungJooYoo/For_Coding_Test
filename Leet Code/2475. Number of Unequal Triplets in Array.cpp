class Solution {
public:
    int unequalTriplets(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int ans = 0;
        
        for (int i = 0; i < LEN; i++) {
            for (int j = i + 1; j < LEN; j++) {
                for (int k = j + 1; k < LEN; k++) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
						ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};

https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/
