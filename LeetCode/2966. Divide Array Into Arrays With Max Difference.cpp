class Solution 
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, const int k) const 
    {
        assert(nums.size() % 3 == 0);
        assert(MIN_N <= nums.size() && nums.size() <= MAX_N);
        assert(MIN_K <= k && k <= MAX_K);
        ranges::sort(nums);

        vector<vector<int>> dividedArrays;
        vector<int> groupOfThree;
        const size_t n = nums.size();

        for (size_t i = 0; i < n; i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
            {
                return {};
            }
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            assert(MIN_NUM <= nums[i + 1] && nums[i + 1] <= MAX_NUM);
            assert(MIN_NUM <= nums[i + 2] && nums[i + 2] <= MAX_NUM);
            groupOfThree.push_back(nums[i]);
            groupOfThree.push_back(nums[i + 1]);
            groupOfThree.push_back(nums[i + 2]);
            dividedArrays.push_back(groupOfThree);
            groupOfThree.clear();
        }

        return dividedArrays;
    }

private:
    enum
    {
        MIN_N   = 1,
        MAX_N   = 100000,
        MIN_NUM = 1,
        MAX_NUM = 100000,
        MIN_K   = 1,
        MAX_K   = 100000
    };
};
