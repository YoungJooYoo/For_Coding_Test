class Solution
{
public:
    vector<int> findValidElements(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        const size_t numsLength = nums.size();
        vector<int> prefixMax(numsLength, 0);
        vector<int> suffixMax(numsLength, 0);
        vector<int> result;

        prefixMax[0] = numeric_limits<int>::min();
        suffixMax[numsLength - 1] = numeric_limits<int>::min();

        if (numsLength <= 2)
        {
            return nums;
        }
        
        for (size_t i = 1; i < numsLength; ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            prefixMax[i] = max(prefixMax[i - 1], nums[i - 1]);
        }
        for (size_t i = numsLength - 1; i > 0; --i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            suffixMax[i - 1] = max(suffixMax[i], nums[i]);
        }

        for (size_t i = 0; i < numsLength; ++i)
        {
            const bool isGreaterThanLeft  = (nums[i] > prefixMax[i]);
            const bool isGreaterThanRight = (nums[i] > suffixMax[i]);
            if (isGreaterThanLeft == true || isGreaterThanRight == true)
            {
                result.push_back(nums[i]);
            }
        }

        assert(result.front() == nums.front());
        assert(result.back() == nums.back());
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM    = 1,
        MAX_NUM    = 100,
    };
};

// https://leetcode.com/problems/valid-elements-in-an-array/description/
