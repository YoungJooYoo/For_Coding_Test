class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {   
        int neg_count = 0;
        int pos_count = 0;

        for (const auto& num : nums) {
            if (num < 0) {
                neg_count++;
            }
            else if (num > 0){
                pos_count++;
            }
        }
            
        return max(neg_count, pos_count);
    }
};

// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
