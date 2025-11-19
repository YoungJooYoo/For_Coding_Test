class Solution
{
public:
    int minOperations(const vector<int>& nums) const
    {
        const size_t LENGTH = nums.size();
        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);
        int onesCount = 0;

        for (const int num : nums)
        {
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            if (num == 1)
            {
                ++onesCount;
            }
        }

        // Case 1: 이미 1이 존재하는 경우
        if (onesCount > 0)
        {
            return static_cast<int>(LENGTH) - onesCount;
        }

        // Case 2: 1이 없는 경우 → gcd가 1인 가장 짧은 연속 구간을 찾아 1을 만들어야 함
        int minOpsToCreateOne = INF;

        for (size_t left = 0; left < LENGTH; ++left)
        {
            int currentGcd = nums[left];
            for (size_t right = left + 1; right < LENGTH; ++right)
            {
                currentGcd = gcd(currentGcd, nums[right]);
                if (currentGcd == 1)
                {
                    const int opsForThisSegment = static_cast<int>(right - left);
                    minOpsToCreateOne = min(minOpsToCreateOne, opsForThisSegment);
                    break; // 가장 짧은 것만 필요
                }
            }
        }

        if (minOpsToCreateOne == INF)
        {
            return IMPOSSIBLE;
        }

        // 첫 1 생성 + (그 1을 이용해 나머지 모두 1로 변경)
        return minOpsToCreateOne + static_cast<int>(LENGTH) - 1;
    }

private:
    static int gcd(int num1, int num2)
    {
        while (num2 != 0)
        {
            num1 %= num2;
            swap(num1, num2);
        }

        return num1;
    }

    enum
    {
        IMPOSSIBLE = -1,
        INF = 1000000000,
        MIN_LENGTH = 2,
        MAX_LENGTH = 50,
        MIN_VALUE = 1,
        MAX_VALUE = 1000000
    };
};

// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/
