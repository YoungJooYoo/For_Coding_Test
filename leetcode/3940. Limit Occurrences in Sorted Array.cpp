class Solution
{
public:
    vector<int> limitOccurrences(const vector<int>& nums, const int k) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);
        assert(MIN_K <= k && k <= static_cast<int>(nums.size()));

        const size_t numsLength = nums.size();
        vector<int> result;
        int currentCount = 0;

        for (size_t i = 0; i < numsLength; ++i)
        {
            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            if (i > 0 && nums[i] == nums[i - 1]) // 이전 원소와 같으면 카운트 증가, 다르면 초기화
            {
                ++currentCount;
            }
            else
            {
                currentCount = 1;
            }

            // k번 이하일 때만 결과에 추가
            if (currentCount <= k)
            {
                result.push_back(nums[i]);
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 1,
        MAX_VALUE  = 100,
        MIN_K      = 1,
    };
};

// 3940. Limit Occurrences in Sorted Array
