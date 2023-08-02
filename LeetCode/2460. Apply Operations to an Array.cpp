class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        vector<int> result;
        
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        for (const auto& num : nums) {
            if (num != 0) result.push_back(num);
        }
        while (result.size() != nums.size()) {
            result.push_back(0);
        }
        // "Or find the number 0 in the nums array and insert it into the result array."

        return result;    
    }
};

// https://leetcode.com/problems/apply-operations-to-an-array/description/
