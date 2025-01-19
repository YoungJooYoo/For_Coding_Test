
class Solution 
{
public:
    int maxAdjacentDistance(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int maxDifference = numeric_limits<int>::min();

        assert(MIN_SIZE <= LENGTH && LENGTH <= MAX_SIZE);

        for (size_t i = 0; i < LENGTH - 1; ++i)
        {
            assert((MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE) && (MIN_VALUE <= nums[i + 1] && nums[i + 1] <= MAX_VALUE));
            const int currentDifference = abs(nums[i + 1] - nums[i]);
            maxDifference = max(maxDifference, currentDifference);
        }

        const int currentDifference = abs(nums[LENGTH - 1] - nums[0]);
        maxDifference = max(maxDifference, currentDifference);

        assert(maxDifference >= 0);
        return maxDifference;
    }

private:
    enum 
    {
        MIN_SIZE = 2,
        MAX_SIZE = 100,
        MIN_VALUE = -100,
        MAX_VALUE = 100
    };
};


// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/

/*

3423. 원형 배열에서 인접 요소 간의 최대 차이

난이도: 쉬움

문제 설명:

원형 배열 nums가 주어질 때, 인접 요소 간의 최대 절대 차이를 찾아주세요.

참고:
원형 배열에서 첫 번째 요소와 마지막 요소도 인접한 것으로 간주합니다.

예제:

예제 1:

입력:
nums = [1, 2, 4]
출력:
3
설명:
배열이 원형이므로, nums[0]과 nums[2]는 인접합니다. 이들의 차이는 
∣
4
−
1
∣
=
3
∣4−1∣=3으로, 최대값입니다.
예제 2:

입력:
nums = [-5, -10, -5]
출력:
5
설명:
nums[0]과 nums[1]의 차이는 
∣
−
5
−
(
−
10
)
∣
=
5
∣−5−(−10)∣=5로, 최대값입니다.
제약 조건:

2
≤
nums.length
≤
100
2≤nums.length≤100
−
100
≤
nums
[
𝑖
]
≤
100
−100≤nums[i]≤100

*/
