class Solution
{
public:
    int minimumSwaps(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        const size_t numsLength = nums.size(); 
        int zeroCount = 0;
        for (const int num : nums)
        {
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            if (num == ZERO)
            {
                ++zeroCount;
            }
        }

        int alreadyInPlaceCount = 0;
        for (size_t i = numsLength - zeroCount; i < numsLength; ++i) // 맨 끝 zeroCount개 자리 중 이미 0인 개수 카운트
        {
            if (nums[i] == ZERO)
            {
                ++alreadyInPlaceCount;
            }
        }

        // 아직 제자리에 없는 0의 개수 = 필요한 최소 스왑 횟수
        return zeroCount - alreadyInPlaceCount;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 0,
        MAX_VALUE  = 100,
        ZERO       = 0,
    };
};

// https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/description/
