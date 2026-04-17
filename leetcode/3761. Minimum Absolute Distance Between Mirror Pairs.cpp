class Solution
{
public:
    int minMirrorPairDistance(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        const size_t numsLength = nums.size();
        unordered_map<int, int> reversedNumToIndex;
        reversedNumToIndex.reserve(numsLength);
        int minDistance = numeric_limits<int>::max();

        for (size_t i = 0; i < numsLength; ++i)
        {
            const int num  = nums[i];
            const int reversedNum = reverseDigitsRecursive(num);
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            const auto it = reversedNumToIndex.find(num);
            if (it != reversedNumToIndex.end())
            {
                const int distance = static_cast<int>(i) - it->second;
                minDistance = min(minDistance, distance);
            }
            reversedNumToIndex[reversedNum] = static_cast<int>(i);
        }

        if (minDistance == numeric_limits<int>::max())
        {
            return FAIL;
        }

        assert(minDistance >= 0);
        return minDistance;
    }

private:
    int reverseDigitsRecursive(const int num) const
    {
        assert(num >= 0);
        int reversedNum = 0;
        int remaining  = num;

        while (remaining > 0)
        {
            const int lastDigit = remaining % 10;
            reversedNum = reversedNum * 10 + lastDigit;
            remaining /= 10;
        }

        assert(reversedNum >= 0);
        return reversedNum;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_VALUE  = 1,
        MAX_VALUE  = 1000000000,
        FAIL       = -1,
    };
};

// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17
