class Solution {
public:
    int minOperations(const vector<int>& nums, const int k) 
    {
        const size_t LEN = nums.size();
        set<int> st;
        int count = 0;

        for (int i = LEN - 1; i >= 0; --i) {
            ++count;
            if (1 <= nums[i] && nums[i] <= k) {
                st.insert(nums[i]);
                if (st.size() == k) {
                    return count;
                }
            }
        }
        
        return count;
    }
};

// https://leetcode.com/problems/minimum-operations-to-collect-elements/
