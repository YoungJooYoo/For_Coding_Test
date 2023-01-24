class Solution {
public:
    int differenceOfSum(vector<int>& nums) 
    {
            // int sum = accumulate(nums.begin(), nums.end(), 0);
            int sum = 0;
            int elem_sum = 0;

            for (const auto& num : nums) {
                sum += num;
                int temp = num;
                while (temp != 0) {
                    elem_sum += temp % 10;
                    temp /= 10;
                }
            }

            return abs(sum - elem_sum);
    }
};

//https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/
