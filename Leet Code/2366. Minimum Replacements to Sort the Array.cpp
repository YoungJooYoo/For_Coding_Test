class Solution {
public:
    long long minimumReplacement(const vector<int>& nums) 
    {
        const int n = nums.size();
        int currentMax = nums[n - 1]; // 마지막 원소를 초기 최대값으로 설정
        long long operations = 0; // 필요한 연산 횟수를 저장할 변수

        // 배열의 마지막에서 두 번째 원소부터 시작하여 첫 번째 원소까지 역순으로 순회
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > currentMax) {
                // 현재 원소가 이전 원소보다 크면, 최소 분할 횟수를 계산
                const int requiredSplits = (nums[i] + currentMax - 1) / currentMax;
                operations += requiredSplits - 1; // 분할 횟수에서 1을 빼서 연산 횟수를 계산
                currentMax = nums[i] / requiredSplits; // 새로운 최대값을 계산
            } else {
                // 현재 원소가 이전 원소보다 작거나 같으면, 최대값을 업데이트
                currentMax = nums[i];
            }
        }

        return operations;
    }
};


// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

/*

### 1. 한국어로 번역

당신은 0부터 시작하는 정수 배열 `nums`를 가지고 있습니다. 한 번의 연산에서 배열의 어떤 원소든 그것과 같은 합을 가지는 두 개의 원소로 대체할 수 있습니다.

예를 들어, `nums = [5,6,7]`을 고려해보세요. 한 번의 연산에서, 우리는 `nums[1]`을 2와 4로 대체하고 `nums`를 `[5,2,4,7]`로 변환할 수 있습니다.

비감소 순서로 정렬된 배열을 만들기 위한 최소 연산 횟수를 반환하세요.

### 2. 요약

- 주어진 배열의 원소를 두 개의 합이 같은 원소로 대체하는 연산을 통해, 전체 배열을 비감소 순서로 정렬하는 데 필요한 최소 연산 횟수를 찾아야 합니다.

### 3. 문제 풀이 방향

이 문제를 해결하기 위한 접근 방법은 다음과 같습니다:

1. **역순으로 생각하기**: 배열을 끝에서부터 앞으로 순회하면서, 각 원소가 이전 원소보다 크거나 같도록 만드는 데 필요한 최소 분할(대체) 횟수를 계산합니다. 이는 배열의 끝에서부터 시작하여, 각 원소를 현재까지의 최소값과 비교하여 조정하는 과정을 포함할 수 있습니다.

2. **분할의 최적화**: 어떤 원소를 분할할 때, 그 원소를 가능한 가장 큰 값과 가장 작은 값으로 분할하는 것이 유리할 수 있습니다. 예를 들어, 원소가 현재까지의 최소값보다 크다면, 그 차이만큼 분할하여 최소값을 맞출 수 있습니다.

3. **수학적 계산**: 각 원소를 분할하는 과정에서, 분할된 원소들이 최종적으로 배열의 나머지 부분과 어떻게 조화를 이루는지 계산해야 합니다. 이는 분할된 원소들이 최소값을 초과하지 않도록 조정하는 것을 포함할 수 있습니다.

4. **그리디 알고리즘**: 이 문제는 그리디 알고리즘의 일종으로 볼 수 있습니다. 각 단계에서 최적의 선택(여기서는 최소 분할 횟수)을 하여 전체 문제의 최적해를 구하는 방식으로 접근할 수 있습니다.

5. **구현**: 문제의 조건을 만족시키기 위해, 각 원소를 순회하면서 필요한 연산을 수행하고, 전체 연산 횟수를 계산합니다. 이 과정에서 현재 원소가 이전 원소(또는 현재까지의 최소값)보다 클 경우, 그 차이를 기반으로 필요한 분할 횟수를 계산하고, 전체 연산 횟수에 추가합니다.

이 문제는 직관적이지 않은 접근 방식을 요구할 수 있으며, 문제를 해결하기 위해서는 배열의 원소들 사이의 관계와 분할 연산이 전체 배열에 미치는 영향을 면밀히 분석해야 합니다.


이 코드의 해당 부분은 배열을 비감소 순서로 만들기 위해 필요한 최소 분할(대체) 연산 횟수를 계산하는 데 중요한 역할을 합니다. 여기서 `-1`을 사용하는 이유를 설명하겠습니다.

```cpp
int requiredSplits = (nums[i] + currentMax - 1) / currentMax;
operations += requiredSplits - 1;
```

### 분할 횟수 계산

`requiredSplits`는 현재 원소(`nums[i]`)를 `currentMax` 값으로 나누어, 해당 원소를 비감소 순서를 유지하면서 분할할 수 있는 최소 횟수를 계산합니다. 여기서 `nums[i] + currentMax - 1`에 `-1`을 더하는 이유는 올림(ceiling) 효과를 구현하기 위함입니다.

- **올림 효과**: `nums[i]`를 `currentMax`로 나눌 때, 나머지가 있으면 분할 횟수를 하나 더해야 합니다. 예를 들어, `nums[i]`가 `10`이고 `currentMax`가 `3`일 경우, 단순히 `10 / 3`을 계산하면 `3`이지만, 실제로는 `10`을 `3`의 배수로 만들기 위해 `4`번 분할해야 합니다(`3, 3, 3, 1`). `-1`을 더하고 나눈 후에 `+1`을 하는 것은 이 올림 계산을 수행하는 방법입니다.

### 연산 횟수 계산

`operations += requiredSplits - 1;`에서 `-1`을 하는 이유는 원소를 분할하는 과정 자체가 이미 하나의 원소를 사용한다는 사실을 반영하기 위함입니다. 즉, `requiredSplits`는 원소를 분할하여 얻어야 하는 새로운 원소의 총 개수를 나타내지만, 실제 "추가로 필요한 연산"의 수는 이보다 하나 적습니다. 원래 원소를 분할하여 첫 번째 새로운 원소를 얻는 것은 추가 연산 없이 가능하기 때문입니다.

- 예를 들어, `requiredSplits`가 `4`라면, 이는 원소 하나를 4개의 새로운 원소로 분할해야 함을 의미합니다. 그러나 첫 번째 분할로 원소 하나가 이미 사용되었기 때문에, 실제로 필요한 "추가 분할 연산"은 `3`회입니다.

이러한 계산 방식은 문제의 요구사항을 정확히 충족시키며, 배열을 비감소 순서로 만들기 위해 필요한 최소한의 연산 횟수를 효율적으로 찾아내는 데 도움을 줍니다.
*/
