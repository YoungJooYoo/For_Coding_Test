class Solution 
{
public:
    vector<int> sortByAbsoluteValue(vector<int>& nums) const
    {
        const size_t LENGTH = nums.size();
        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                if (abs(nums[i]) > abs(nums[j]))
                {
                    swap(nums[i], nums[j]);
                }
            }
        }

        return nums;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = - 100,
        MAX_NUM = 100
    };
};

// https://leetcode.com/problems/sort-array-by-absolute-value/description/
