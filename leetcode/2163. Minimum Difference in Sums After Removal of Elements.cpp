class Solution
{
public:
    long long minimumDifference(vector<int>& nums)
    {
        const size_t length = nums.size();
        const size_t n = length / DIVISOR;
        vector<long long> leftSums(2 * n + 1, 0);
        vector<long long> rightSums(2 * n + 1, 0);
        priority_queue<int> leftHeap;
        long long leftSum = 0;

        assert(length % DIVISOR == 0 && length % 3 == 0);
        assert(MIN_N <= n && n <= MAX_N);

        for (size_t i = 0; i < 2 * n; ++i) // 왼쪽: n개 "가장 큰 수" 유지 (최소합)
        {
            leftSum += nums[i];
            leftHeap.push(nums[i]);
            if (leftHeap.size() > n)
            {
                leftSum -= leftHeap.top();
                leftHeap.pop();
            }
            if (leftHeap.size() == n)
            {
                leftSums[i + 1] = leftSum;
            }
        }

        priority_queue<int, vector<int>, greater<int>> rightHeap; // 오른쪽: n개 "가장 작은 수" 유지 (최대합)
        long long rightSum = 0;
        for (size_t i = 3 * n; i > n; --i)
        {
            rightSum += nums[i - 1];
            rightHeap.push(nums[i - 1]);
            if (rightHeap.size() > n)
            {
                rightSum -= rightHeap.top();
                rightHeap.pop();
            }
            if (rightHeap.size() == n)
            {
                rightSums[i - 1] = rightSum;
            }
        }

        long long answer = LLONG_MAX;
        for (size_t i = n; i <= 2 * n; ++i)
        {
            const long long diff = leftSums[i] - rightSums[i];
            if (diff < answer)
            {
                answer = diff;
            }
        }
        return answer;
    }

private:
    enum
    {
        DIVISOR = 3,
        MIN_N = 1,
        MAX_N = 100000,
        MIN_NUM = 1,
        MAX_NUM = 100000
    };
};

// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/?envType=daily-question&envId=2025-07-18
