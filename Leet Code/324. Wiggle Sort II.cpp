class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        priority_queue<int> q(nums.begin(), nums.end());

        // odd index and even index
        for (size_t i = 1; i < LEN; i += 2) {
            nums[i] = q.top(); 
            q.pop();
        }
        for (size_t i = 0; i < LEN; i += 2) {
            nums[i] = q.top(); 
            q.pop();
        }
    }
};

// https://leetcode.com/problems/wiggle-sort-ii/description/
