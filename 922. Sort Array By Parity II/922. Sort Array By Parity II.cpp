class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        vector<int> odd;
        vector<int> even;

        for (const auto& num : nums) {
            if (num % 2 == 0) {
                even.push_back(num);
            }
            else {
                odd.push_back(num);
            }
        }

        for (size_t i = 0; i < nums.size() / 2; ++i) {
            nums[2 * i] = even[i];
            nums[2 * i + 1] = odd[i];
        }

        return nums;    
    }
};

// https://leetcode.com/problems/sort-array-by-parity-ii/description/
