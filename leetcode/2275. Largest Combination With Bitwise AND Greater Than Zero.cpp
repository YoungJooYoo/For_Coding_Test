class Solution 
{
public:
    int largestCombination(const std::vector<int>& candidates) 
    {
        std::vector<int> bitCounts(BIT_LIMIT, 0);

        for (const int number : candidates) 
        {
            for (int bit = 0; bit < BIT_LIMIT; ++bit) // 모든 숫자에 대해 각 비트가 set된 횟수를 카운트
            {
                if ((number & (1 << bit)) != 0) 
                {
                    ++bitCounts[bit];
                }
            }
        }

        // 가장 많이 set된 비트의 개수를 찾음
        return *std::max_element(bitCounts.begin(), bitCounts.end());
    }

private:
    enum { BIT_LIMIT = 31 };  // 각 비트 위치별로 set된 숫자의 개수를 저장할 벡터
};

// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/?envType=daily-question&envId=2024-11-07
