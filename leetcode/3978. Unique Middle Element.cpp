class Solution
{
public:
    bool isMiddleElementUnique(const vector<int>& nums)
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        assert(nums.size() % 2 == 1);

        const int midElement = nums[nums.size() / 2];
        unordered_map<int, size_t> frequency;

        for (const int num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++frequency[num];
        }

        return (frequency[midElement] == 1) ? true : false;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 1,
        MAX_NUM = 100
    };
};

// https://leetcode.com/problems/unique-middle-element/description/
