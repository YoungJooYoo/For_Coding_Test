class Solution {
public:
    int minDifference(vector<int>& nums) 
    {
        if (nums.size() <= 4) {
            return 0;
        }

        sort(nums.begin(), nums.end(), greater<int>());
        const size_t LEN =  nums.size();
        const int min[4] = {abs(nums[LEN - 4] - nums[0]), abs(nums[LEN - 3] - nums[1]), abs(nums[LEN - 2] - nums[2]), abs(nums[LEN - 1] - nums[3])};
        
        return *min_element(min, min + 4);
    }
};

// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

/*
### 한국어 번역

1509. 세 번의 이동으로 최대값과 최소값의 차이 최소화
난이도: 중간
주제: [정보 없음]
회사: [정보 없음]
힌트: 정수 배열 `nums`가 주어집니다.

한 번의 이동으로, `nums`의 한 요소를 아무 값으로나 변경할 수 있습니다.

최대 세 번의 이동을 수행한 후 `nums`의 최대값과 최소값의 차이가 최소가 되도록 합니다.

#### 예시 1:

입력: nums = [5,3,2,4]
출력: 0
설명: 최대 3번의 이동을 할 수 있습니다.
첫 번째 이동에서, 2를 3으로 변경합니다. `nums`는 [5,3,3,4]가 됩니다.
두 번째 이동에서, 4를 3으로 변경합니다. `nums`는 [5,3,3,3]이 됩니다.
세 번째 이동에서, 5를 3으로 변경합니다. `nums`는 [3,3,3,3]이 됩니다.
3번의 이동 후, 최소값과 최대값의 차이는 3 - 3 = 0입니다.

#### 예시 2:

입력: nums = [1,5,0,10,14]
출력: 1
설명: 최대 3번의 이동을 할 수 있습니다.
첫 번째 이동에서, 5를 0으로 변경합니다. `nums`는 [1,0,0,10,14]가 됩니다.
두 번째 이동에서, 10을 0으로 변경합니다. `nums`는 [1,0,0,0,14]가 됩니다.
세 번째 이동에서, 14를 1로 변경합니다. `nums`는 [1,0,0,0,1]이 됩니다.
3번의 이동 후, 최소값과 최대값의 차이는 1 - 0 = 1입니다.
3번의 이동으로 차이를 0으로 만들 수 없음을 보여줄 수 있습니다.

#### 예시 3:

입력: nums = [3,100,20]
출력: 0
설명: 최대 3번의 이동을 할 수 있습니다.
첫 번째 이동에서, 100을 7로 변경합니다. `nums`는 [3,7,20]이 됩니다.
두 번째 이동에서, 20을 7로 변경합니다. `nums`는 [3,7,7]이 됩니다.
세 번째 이동에서, 3을 7로 변경합니다. `nums`는 [7,7,7]이 됩니다.
3번의 이동 후, 최소값과 최대값의 차이는 7 - 7 = 0입니다.

#### 제약 조건:

- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9

### 요약

이 문제는 주어진 배열에서 최대 세 번의 값 변경을 통해 배열의 최대값과 최소값의 차이를 최소화하는 것입니다.

### 문제 풀이 방향

1. **정렬**: 배열을 정렬하여 문제를 단순화할 수 있습니다.

2. **경우의 수 분석**: 최대 세 번의 변경으로 가능한 경우의 수는 다음과 같습니다.
   - 최대값 3개를 제거하거나,
   - 최대값 2개와 최소값 1개를 제거하거나,
   - 최대값 1개와 최소값 2개를 제거하거나,
   - 최소값 3개를 제거합니다.

3. **최소 차이 계산**: 각 경우에 대해 최소값과 최대값의 차이를 계산하고, 이 중 최소 차이를 반환합니다.

이 접근 방법을 사용하면, 최대 세 번의 변경으로 가능한 최소 차이를 효율적으로 찾을 수 있습니다.
*/
