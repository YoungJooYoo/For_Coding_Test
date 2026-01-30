class Solution 
{
public:
    int centeredSubarrays(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const size_t LENGTH = nums.size();
        int result = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            for (size_t j = i; j < LENGTH; ++j)
            {
                const int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
                const auto found = find(nums.begin() + i, nums.begin() + j + 1, sum);
                if (found != nums.begin() + j + 1)
                {
                    ++result;
                }
            }
        }

        assert(result >= 0);
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 500,
        MIN_VALUE = -100000,
        MAX_VALUE = 100000
    };
};

// https://leetcode.com/problems/number-of-centered-subarrays/description/
