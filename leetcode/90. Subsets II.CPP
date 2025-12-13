class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        ranges::sort(nums);
        generateSubsets(nums, 0);
        return mResult;
    }

private:
    void generateSubsets(const vector<int>& nums, const size_t startIndex)
    {
        mResult.push_back(mCurrent);

        for (size_t i = startIndex; i < nums.size(); ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            if (i == startIndex || nums[i] != nums[i - 1])
            {
                mCurrent.push_back(nums[i]);
                generateSubsets(nums, i + 1);
                mCurrent.pop_back();
            }
        }
    }

private:
    vector<int> mCurrent;
    vector<vector<int>> mResult;

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 10,
        MIN_NUM = -10,
        MAX_NUM = 10
    };
};

// https://leetcode.com/problems/subsets-ii/description/
