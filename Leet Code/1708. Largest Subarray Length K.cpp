class Solution {
public:
    vector<int> largestSubarray(const  vector<int>& nums, const  int k) 
    {
        int pos = 0;

        for (int i = 0, cur = 0; i <= nums.size() - k; ++i) {
            if (nums[i] > cur){
                cur = nums[i];
                pos = i;
            }
        }

        return vector<int>(nums.begin() + pos, nums.begin() + pos + k);
    }
};
// https://leetcode.com/problems/largest-subarray-length-k/description/
