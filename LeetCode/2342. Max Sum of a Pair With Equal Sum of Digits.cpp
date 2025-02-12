class Solution 
{
public:
    int maximumSum(const vector<int>& nums) 
    {
        assert(nums.size() >= MIN_NUMS_SIZE && nums.size() <= MAX_NUMS_SIZE);

        unordered_map<int, priority_queue<int>> digitSumToNumbersPQ;
        int maxPairSum = -1;

        for (const auto& number : nums)
        {
            assert(number >= MIN_VALUE && number <= MAX_VALUE);
            const int digitSum = calculateDigitSum(number);
            digitSumToNumbersPQ[digitSum].push(number);
        }
        
        for (auto& entry : digitSumToNumbersPQ)
        {
            auto& numbersPQ = entry.second;
            if (numbersPQ.size() >= MIN_PQ_SIZE)
            {
                int currentPairSum = 0;
                currentPairSum += numbersPQ.top(); numbersPQ.pop();
                currentPairSum += numbersPQ.top(); numbersPQ.pop();
                maxPairSum = max(maxPairSum, currentPairSum);
            }
        }

        return maxPairSum;
    }

private:
    int calculateDigitSum(int number) const
    {
        int sum = 0;

        while (number != 0)
        {
            sum += number % DECIMAL;
            number /= DECIMAL;
        }

        return sum;
    }

private:
    enum 
    {
        MIN_NUMS_SIZE = 1,
        MAX_NUMS_SIZE = 100000,      // 10^5
        MIN_VALUE     = 1,
        MAX_VALUE     = 1000000000,   // 10^9
        DECIMAL = 10,
        MIN_PQ_SIZE = 2,

    };
};


// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

/*
문제 번역
2342. 각 자리수의 합이 같은 쌍의 최대 합
Medium

문제 설명:
양의 정수로 구성된 0-인덱스 배열 nums가 주어집니다.
서로 다른 두 인덱스 i와 j (i ≠ j)를 선택할 수 있으며, 조건은 **nums[i]**와 **nums[j]**의 각 자리수의 합이 서로 같아야 합니다.

조건을 만족하는 모든 인덱스 쌍 (i, j) 중에서, **nums[i] + nums[j]**의 최댓값을 반환하세요.
만약 조건을 만족하는 두 수가 존재하지 않으면 -1을 반환합니다.

예제 1:

입력: nums = [18,43,36,13,7]
출력: 54
설명:
(0, 2): 두 수 모두 각 자리수의 합이 9이고, 합은 18 + 36 = 54
(1, 4): 두 수 모두 각 자리수의 합이 7이고, 합은 43 + 7 = 50
→ 최대 합은 54입니다.
예제 2:

입력: nums = [10,12,19,14]
출력: -1
설명: 조건을 만족하는 두 수가 없으므로 -1을 반환합니다.
제약 조건:

1 <= nums.length <= 10⁵
1 <= nums[i] <= 10⁹
*/
