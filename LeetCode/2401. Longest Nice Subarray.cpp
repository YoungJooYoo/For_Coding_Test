class Solution 
{
public:
    int longestNiceSubarray(const vector<int>& nums) const
    {
        assert(nums.size() >= MIN_ARRAY_SIZE && nums.size() <= MAX_ARRAY_SIZE);

        const int n = nums.size();
        int maxLength = 0;
        int currentMask = 0;
        int left = 0;

        for (int right = 0; right < n; ++right)
        {
            assert(nums[right] >= MIN_NUM && nums[right] <= MAX_NUM);
            while ((currentMask & nums[right]) != 0)
            {
                currentMask ^= nums[left++]; // 윈도우 왼쪽의 원소를 제거하여 mask 업데이트
                assert(left < n);
            }
            currentMask |= nums[right]; // 충돌이 없으므로 현재 원소를 윈도우에 추가
            assert(right - left + 1 >= 0);
            maxLength = max(maxLength, right - left + 1);
        }

        assert(maxLength >= 1);
        return maxLength;
    }

private:
    enum
    {
        MIN_ARRAY_SIZE = 1,
        MAX_ARRAY_SIZE = 100000,
        MIN_NUM = 1,
        MAX_NUM = 1000000000 // 10^9
    };
};

// https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18
