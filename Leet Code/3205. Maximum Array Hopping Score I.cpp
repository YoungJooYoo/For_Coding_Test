class Solution 
{
public:
    int maxScore(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        vector<int> dp(LENGTH, 0);

        for (size_t i = 0; i < LENGTH; ++i)
        {
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                dp[j] = max(dp[j], dp[i] + static_cast<int>(j - i) * nums[j]);
            }
        }

        return dp[LENGTH - 1];    
    }
};

// https://leetcode.com/problems/maximum-array-hopping-score-i/description/

/*

3205. 최대 배열 점프 점수 I

난이도: 중간

문제 설명
배열 nums가 주어질 때, 인덱스 0에서 시작하여 배열의 마지막 요소에 도달할 때까지 최대 점수를 얻어야 합니다.

각 점프에서, 인덱스 i에서 인덱스 j (j > i)로 점프할 수 있으며, 점수는 (j - i) * nums[j]입니다.

최대 점수를 반환하세요.

예제
예제 1:

입력: nums = [1,5,8]
출력: 16
설명:
마지막 요소에 도달하는 두 가지 방법이 있습니다:
0 -> 1 -> 2: 점수는 (1 - 0) * 5 + (2 - 1) * 8 = 13.
0 -> 2: 점수는 (2 - 0) * 8 = 16.
예제 2:

입력: nums = [4,5,2,8,9,1,3]
출력: 42
설명:
점프 방법은 0 -> 4 -> 6으로, 점수는 (4 - 0) * 9 + (6 - 4) * 3 = 42.
제약 조건
2 <= nums.length <= 103
1 <= nums[i] <= 105
*/
