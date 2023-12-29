class Solution {
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); i += 2) {
            swap(nums[i], nums[i - 1]);
        }

        return nums;
    }
};

// https://leetcode.com/problems/minimum-number-game/description/
