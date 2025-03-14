class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const size_t LENGTH = nums.size();
        size_t i = 0;
        int result = 0;
        int count = 0;

        for (const auto& num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++mFreq[num];
        }

        for (const auto& elem : mFreq)
        {
            const int number = elem.first;
            const int count = elem.second;
            mNums.push_back(number);
            if (count >= 2)
            {
                mNums.push_back(number);
            }
        }

        nums = mNums;
        return mNums.size();
    }

private:
    map<int, int> mFreq;
    vector<int> mNums;

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 3 * 10000,
        MIN_NUM = -10000,
        MAX_NUM = 10000
    };
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
