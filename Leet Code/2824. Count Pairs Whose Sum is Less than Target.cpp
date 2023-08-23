class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        const size_t LEN = nums.size();
        int count = 0;
        

        for (size_t i = 0; i < LEN; ++i) {
            for (size_t j = i + 1; j < LEN; ++j) {
                nums[i] + nums[j] < target ? ++count : CONTINUE;
            }
        } 

        return count;    
    }

private :
    enum { CONTINUE = 99 };
};

// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
