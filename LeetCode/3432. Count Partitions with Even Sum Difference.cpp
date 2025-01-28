class Solution 
{
public:
    int countPartitions(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        int leftPartitionSum = 0;
        int rightPartitionSum = accumulate(nums.begin(), nums.end(), 0); 
        int validPartitionCount = 0; 

        assert(MIN_NUM_SIZE <= LENGTH && LENGTH <= MAX_NUM_SIZE);
        for (size_t i = 0; i < LENGTH - 1; ++i) 
        {
            assert(MIN_NUM_VALUE <= nums[i] && nums[i] <= MAX_NUM_VALUE);
            leftPartitionSum += nums[i];
            rightPartitionSum -= nums[i];

            if ((leftPartitionSum - rightPartitionSum) % 2 == 0) 
            {
                ++validPartitionCount;
            }
        }

        return validPartitionCount;
    }

private:
    enum  
    {
        MIN_NUM_SIZE = 2,
        MAX_NUM_SIZE = 100,
        MIN_NUM_VALUE = 1,
        MAX_NUM_VALUE = 100
    };
};


// https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/

/*
3432. 짝수 합 차이를 가지는 분할의 개수
문제 설명
길이가 n인 정수 배열 nums가 주어집니다.

**분할(partition)**은 배열을 두 개의 **비어 있지 않은 부분 배열(subarray)**로 나누는 **인덱스 i**를 의미합니다.
이때 다음 조건이 만족되어야 합니다:

0 <= i < n - 1
왼쪽 부분 배열은 [0, i]의 인덱스를 포함합니다.
오른쪽 부분 배열은 [i + 1, n - 1]의 인덱스를 포함합니다.
목표:
왼쪽 부분 배열의 합과 오른쪽 부분 배열의 합의 차이가 짝수가 되는 분할의 개수를 반환하세요.

입출력 예제
예제 1
입력:

plaintext
복사
편집
nums = [10, 10, 3, 7, 6]
출력:

plaintext
복사
편집
4
설명:
4개의 분할에서 차이가 짝수입니다:

[10], [10, 3, 7, 6] → 차이: 10 - 26 = -16 (짝수)
[10, 10], [3, 7, 6] → 차이: 20 - 16 = 4 (짝수)
[10, 10, 3], [7, 6] → 차이: 23 - 13 = 10 (짝수)
[10, 10, 3, 7], [6] → 차이: 30 - 6 = 24 (짝수)
예제 2
입력:

plaintext
복사
편집
nums = [1, 2, 2]
출력:

plaintext
복사
편집
0
설명:
어떤 분할에서도 차이가 짝수가 되지 않습니다.

예제 3
입력:

plaintext
복사
편집
nums = [2, 4, 6, 8]
출력:

plaintext
복사
편집
3
설명:
모든 분할에서 차이가 짝수입니다:

[2], [4, 6, 8] → 차이: 2 - 18 = -16 (짝수)
[2, 4], [6, 8] → 차이: 6 - 14 = -8 (짝수)
[2, 4, 6], [8] → 차이: 12 - 8 = 4 (짝수)
제약 조건
1 <= nums.length <= 10^5
1 <= nums[i] <= 1000

*/
