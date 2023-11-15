class Solution {
public:
    int sumCounts(const vector<int>& nums) 
    {   
        const size_t LEN = nums.size();
        int result =  0;

        for (size_t i = 0; i < LEN; ++i) {
            set<int> temp;
            for (size_t j = i; j < LEN; ++j) {
                temp.insert(nums[j]);
                result += pow(temp.size(), 2);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/
