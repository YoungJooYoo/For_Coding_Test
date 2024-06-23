class Solution 
{
public:
    int minimumOperations(const vector<int>& nums) 
    {
        int count = 0;

        for (const auto& num : nums)
        {
            if (num % 3 != 0) ++count;
        }

        return count;
    }
};

// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

/*

3190. 모든 요소를 3으로 나눌 수 있게 만들기 위한 최소 연산 수 찾기
난이도: 쉬움

문제 설명
정수 배열 nums가 주어집니다. 한 번의 연산에서, nums의 어떤 요소에 1을 더하거나 뺄 수 있습니다.

모든 요소가 3으로 나눌 수 있도록 만들기 위해 필요한 최소 연산 수를 반환하세요.

예제
예제 1:

입력: nums = [1, 2, 3, 4]
출력: 3
설명:
모든 배열 요소를 3으로 나눌 수 있게 만들기 위해 3번의 연산이 필요합니다:
1에서 1을 뺍니다.
2에 1을 더합니다.
4에서 1을 뺍니다.
예제 2:

입력: nums = [3, 6, 9]
출력: 0
설명:
모든 배열 요소가 이미 3으로 나눌 수 있으므로 연산이 필요하지 않습니다.
제약 조건
1 <= nums.length <= 50
1 <= nums[i] <= 50
*/
