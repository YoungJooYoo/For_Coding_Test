class Solution {
public:
    int smallestEqual(vector<int>& nums) 
    {
        for (size_t i = 0; i < nums.size(); ++i) {
            int index = i % 10;
            if (nums[i] == index) return i;
        }

        return -1;
    }
};


https://leetcode.com/problems/smallest-index-with-equal-value/description/
