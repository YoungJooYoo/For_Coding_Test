class Solution 
{
public:
    int dominantIndices(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const size_t LENGTH = nums.size();
        int count = 0;

        for (int i = 0; i < LENGTH - 1; ++i)
        {
            const int val = accumulate(nums.begin() + i + 1, nums.end(), 0) / static_cast<double>(LENGTH - (i + 1));
            if (nums[i] > val)
            {
                ++count;
            }

        }

        assert(count >= 0);
        return count;
    }

private :
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 100
    };
};

// https://leetcode.com/problems/count-dominant-indices/description/
