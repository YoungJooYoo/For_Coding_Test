class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> positive;
        vector<int> negative;

        for (const auto& num : nums) {
            if (num < 0) {
                negative.push_back(num);
            }
            else {
                positive.push_back(num);
            }
        }    

        nums.clear();
        for (size_t i = 0; i < positive.size(); ++i) {
            nums.push_back(positive[i]);
            nums.push_back(negative[i]);
        }

        return nums;
    }
};

// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
