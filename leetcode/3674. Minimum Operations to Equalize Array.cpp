class Solution 
{
public:
    int minOperations(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        const size_t LENGTH = nums.size();
        
        for (size_t i = 0; i < LENGTH - 1; ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            assert(MIN_NUM <= nums[i + 1] && nums[i + 1] <= MAX_NUM);
            if (nums[i] != nums[i + 1])
            {
                return 1;
            }
        }
        
        return 0;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 100000
    };
};

// https://leetcode.com/problems/minimum-operations-to-equalize-array/description/
