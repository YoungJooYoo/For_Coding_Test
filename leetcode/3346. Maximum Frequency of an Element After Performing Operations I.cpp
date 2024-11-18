class Solution 
{
public:
    int maxFrequency(const vector<int>& nums, const int k, const int numOperations) const
    {
        const int maxElementValue = *max_element(nums.begin(), nums.end());
        const int frequencyArraySize = maxElementValue + k + 2; // 충분한 공간
        vector<int> frequency(frequencyArraySize, 0);
        
        for (const int num : nums) // nums의 빈도 값을 미리 계산
        {
            ++frequency[num];
        }

        vector<int> prefixSum(frequencyArraySize, 0); // prefixSum[i]는 frequency[0]부터 frequency[i]까지의 누적된 합을 나타냅니다.
        prefixSum[0] = frequency[0];
        for (int i = 1; i < frequencyArraySize; ++i) // Create prefix sum array
        {
            prefixSum[i] = prefixSum[i - 1] + frequency[i];
        }

        int maxFrequency = 0;
        for (int targetValue = 0; targetValue < frequencyArraySize; ++targetValue) // Iterate through possible target values
        {
            if (!(frequency[targetValue] == 0 && numOperations == 0))
            {
                const int leftBoundary = max(0, targetValue - k);
                const int rightBoundary = min(frequencyArraySize - 1, targetValue + k);
                const int totalInRange = prefixSum[rightBoundary] - (leftBoundary > 0 ? prefixSum[leftBoundary - 1] : 0);
                const int requiredAdjustments = totalInRange - frequency[targetValue];
                const int achievableFrequency = frequency[targetValue] + min(numOperations, requiredAdjustments);
                maxFrequency = max(maxFrequency, achievableFrequency);
            }
        }

        return maxFrequency;
    }
};

// class Solution 
{
public:
    int maxFrequency(const vector<int>& nums, const int k, const int numOperations) const
    {
        const int maxElementValue = *max_element(nums.begin(), nums.end());
        const int frequencyArraySize = maxElementValue + k + 2; // 충분한 공간
        vector<int> frequency(frequencyArraySize, 0);
        
        for (const int num : nums) // nums의 빈도 값을 미리 계산
        {
            ++frequency[num];
        }

        vector<int> prefixSum(frequencyArraySize, 0); // prefixSum[i]는 frequency[0]부터 frequency[i]까지의 누적된 합을 나타냅니다.
        prefixSum[0] = frequency[0];
        for (int i = 1; i < frequencyArraySize; ++i) // Create prefix sum array
        {
            prefixSum[i] = prefixSum[i - 1] + frequency[i];
        }

        int maxFrequency = 0;
        for (int targetValue = 0; targetValue < frequencyArraySize; ++targetValue) // Iterate through possible target values
        {
            if (!(frequency[targetValue] == 0 && numOperations == 0))
            {
                const int leftBoundary = max(0, targetValue - k);
                const int rightBoundary = min(frequencyArraySize - 1, targetValue + k);
                const int totalInRange = prefixSum[rightBoundary] - (leftBoundary > 0 ? prefixSum[leftBoundary - 1] : 0);
                const int requiredAdjustments = totalInRange - frequency[targetValue];
                const int achievableFrequency = frequency[targetValue] + min(numOperations, requiredAdjustments);
                maxFrequency = max(maxFrequency, achievableFrequency);
            }
        }

        return maxFrequency;
    }
};

/*

**3346. 연산을 수행한 후 요소의 최대 빈도 I**  
난이도: 중간

---

정수 배열 `nums`와 두 개의 정수 `k` 및 `numOperations`가 주어집니다.

`nums`에서 **`numOperations`번**의 연산을 수행해야 합니다. 각 연산에서 다음을 수행합니다:

1. 이전 연산에서 선택되지 않은 인덱스 `i`를 선택합니다.
2. `nums[i]`에 **`[-k, k]` 범위**에 있는 정수를 더합니다.

연산을 모두 수행한 후, `nums`에서 **어떤 요소의 최대 빈도**를 반환하세요.

---

### 예제 1:

입력:
```
nums = [1,4,5], k = 1, numOperations = 2
```
출력:
```
2
```
설명:

다음과 같은 방식으로 최대 빈도를 2로 만들 수 있습니다:
1. `nums[1]`에 0을 더합니다. 결과 배열은 `[1, 4, 5]`가 됩니다.
2. `nums[2]`에 -1을 더합니다. 결과 배열은 `[1, 4, 4]`가 됩니다.

최대 빈도는 `4`가 2번 등장하는 것이므로, 결과는 `2`입니다.

### 예제 2:

입력:
```
nums = [5,11,20,20], k = 5, numOperations = 1
```
출력:
```
2
```
설명:

다음과 같은 방식으로 최대 빈도를 2로 만들 수 있습니다:
1. `nums[1]`에 0을 더합니다. 결과 배열은 `[5, 11, 20, 20]`이 됩니다.

`20`이 2번 등장하므로, 최대 빈도는 `2`입니다.

---

### 제약 사항:

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`
- `0 <= numOperations <= nums.length`

이 문제는 주어진 배열에서 연산을 통해 어떤 요소의 빈도를 최대로 높이는 것입니다. 각 연산에서 이전에 선택되지 않은 인덱스를 선택하고, 해당 인덱스의 값을 범위 `[-k, k]`에서 조정하여 최종적으로 배열 내 요소 중 최대 빈도를 찾아 반환하는 것이 목표입니다.
*/

/*

**3346. 연산을 수행한 후 요소의 최대 빈도 I**  
난이도: 중간

---

정수 배열 `nums`와 두 개의 정수 `k` 및 `numOperations`가 주어집니다.

`nums`에서 **`numOperations`번**의 연산을 수행해야 합니다. 각 연산에서 다음을 수행합니다:

1. 이전 연산에서 선택되지 않은 인덱스 `i`를 선택합니다.
2. `nums[i]`에 **`[-k, k]` 범위**에 있는 정수를 더합니다.

연산을 모두 수행한 후, `nums`에서 **어떤 요소의 최대 빈도**를 반환하세요.

---

### 예제 1:

입력:
```
nums = [1,4,5], k = 1, numOperations = 2
```
출력:
```
2
```
설명:

다음과 같은 방식으로 최대 빈도를 2로 만들 수 있습니다:
1. `nums[1]`에 0을 더합니다. 결과 배열은 `[1, 4, 5]`가 됩니다.
2. `nums[2]`에 -1을 더합니다. 결과 배열은 `[1, 4, 4]`가 됩니다.

최대 빈도는 `4`가 2번 등장하는 것이므로, 결과는 `2`입니다.

### 예제 2:

입력:
```
nums = [5,11,20,20], k = 5, numOperations = 1
```
출력:
```
2
```
설명:

다음과 같은 방식으로 최대 빈도를 2로 만들 수 있습니다:
1. `nums[1]`에 0을 더합니다. 결과 배열은 `[5, 11, 20, 20]`이 됩니다.

`20`이 2번 등장하므로, 최대 빈도는 `2`입니다.

---

### 제약 사항:

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`
- `0 <= numOperations <= nums.length`

이 문제는 주어진 배열에서 연산을 통해 어떤 요소의 빈도를 최대로 높이는 것입니다. 각 연산에서 이전에 선택되지 않은 인덱스를 선택하고, 해당 인덱스의 값을 범위 `[-k, k]`에서 조정하여 최종적으로 배열 내 요소 중 최대 빈도를 찾아 반환하는 것이 목표입니다.
*/
