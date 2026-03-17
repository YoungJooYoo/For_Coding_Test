class Solution
{
public:
    int firstUniqueEven(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        unordered_map<int, int> freq;

        for (const auto num : nums)
        {
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            if (num % 2 == 0)
            {
                ++freq[num];
            }
        }

        for (const auto num : nums)
        {
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            if (num % 2 == 0)
            {
                if (freq[num] == 1)
                {
                    return num;
                }
            }
        }

        return FAIL;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 1,
        MAX_VALUE  = 100,
        FAIL       = -1,
    };
};

// https://leetcode.com/problems/first-unique-even-element/description/
