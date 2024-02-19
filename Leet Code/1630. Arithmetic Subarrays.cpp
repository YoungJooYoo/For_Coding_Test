class Solution {
public:
    bool is_arithmetic_subarrays(const auto& sub_arr)
    {
        const int diff = sub_arr[1] - sub_arr[0];
        const size_t LEN = sub_arr.size();

        for (size_t i = 1; i < LEN; ++i) {
            if (sub_arr[i] - sub_arr[i - 1] != diff) return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        const size_t LEN = l.size();
        vector<bool> result;

        for (size_t i = 0; i < LEN; ++i) {
            const int start = l[i];
            const int end = r[i];
            vector<int> sub_arr;
            for  (size_t j  = start; j <= end; ++j) {
                sub_arr.push_back(nums[j]);
            }
            sort(sub_arr.begin(), sub_arr.end());
            result.push_back(is_arithmetic_subarrays(sub_arr));
        }

        return result;
    }
};

// https://leetcode.com/problems/arithmetic-subarrays/description/

/*

### 문제 번역

1630. 산술 부분 배열
난이도: 중간

숫자의 수열이 적어도 두 개의 원소를 포함하며 모든 연속된 두 원소의 차이가 같을 때, 이 수열을 산술 수열이라고 합니다. 보다 형식적으로, 수열 `s`가 산술 수열이 되려면 모든 유효한 `i`에 대해 `s[i+1] - s[i] == s[1] - s[0]`을 만족해야 합니다.

예를 들어, 다음은 산술 수열입니다:
- 1, 3, 5, 7, 9
- 7, 7, 7, 7
- 3, -1, -5, -9

다음 수열은 산술 수열이 아닙니다:
- 1, 1, 2, 5, 7

`n`개의 정수로 이루어진 배열 `nums`와 `m`개의 정수로 이루어진 두 배열 `l`과 `r`이 주어집니다. 여기서 `l`과 `r`은 `m`개의 범위 쿼리를 나타내며, `i`번째 쿼리는 범위 `[l[i], r[i]]`를 나타냅니다. 모든 배열은 0-인덱스를 사용합니다.

`nums[l[i]], nums[l[i]+1], ..., nums[r[i]]`의 부분 배열을 재배열하여 산술 수열을 형성할 수 있다면 `true`, 그렇지 않다면 `false`를 포함하는 불리언 요소의 리스트 `answer`를 반환합니다.

### 요약

- 주어진 배열 `nums`에서, 각 쿼리 `[l[i], r[i]]`에 대해 해당 범위의 부분 배열이 산술 수열을 이룰 수 있는지 여부를 판단해야 합니다.
- 부분 배열을 산술 수열로 만들 수 있다면 `true`, 만들 수 없다면 `false`를 반환하는 리스트를 생성합니다.
- 산술 수열은 모든 연속된 두 원소의 차이가 동일한 수열을 의미합니다.

### 풀이 방향

- 각 쿼리에 대해, 해당하는 부분 배열을 추출합니다.
- 추출한 부분 배열을 정렬하여 모든 연속된 두 원소의 차이가 동일한지 확인합니다.
- 모든 차이가 동일하다면, 해당 부분 배열은 재배열을 통해 산술 수열을 이룰 수 있으므로 `true`를, 그렇지 않다면 `false`를 결과 리스트에 추가합니다.
- 모든 쿼리를 처리한 후, 결과 리스트를 반환합니다.


이 문제를 해결하기 위해서는 각 쿼리에 대해 주어진 서브어레이가 산술 수열(arithmetic sequence)을 이룰 수 있는지 확인해야 합니다. 산술 수열이 되기 위해서는 수열의 모든 연속된 두 원소의 차이가 동일해야 합니다. 이를 확인하는 한 가지 방법은 서브어레이를 정렬하고, 모든 연속된 원소 쌍 사이의 차이가 동일한지 확인하는 것입니다.




### 알고리즘

1. 결과를 저장할 불리언 리스트 `answer`를 초기화합니다.
2. 각 쿼리 `[l[i], r[i]]`에 대해 다음 단계를 수행합니다:
   - 서브어레이 `nums[l[i]]`부터 `nums[r[i]]`까지를 추출하고 복사본을 만듭니다.
   - 추출한 서브어레이를 정렬합니다.
   - 정렬된 서브어레이에서 모든 연속된 원소 쌍의 차이가 동일한지 확인합니다. 첫 번째 원소 쌍의 차이를 기준으로 삼고, 이후 모든 원소 쌍의 차이가 이 기준과 동일한지 비교합니다.
   - 모든 차이가 동일하다면, 이 서브어레이는 산술 수열을 이룰 수 있으므로 `answer`에 `true`를 추가합니다. 그렇지 않다면 `false`를 추가합니다.
3. 모든 쿼리를 처리한 후 `answer`를 반환합니다.



### 복잡도 분석

- **시간 복잡도**: 각 쿼리마다 서브어레이를 정렬하는 데 `O(k log k)`의 시간이 소요됩니다(`k`는 서브어레이의 길이). 최악의 경우 모든 쿼리가 전체 배열을 대상으로 할 수 있으므로, 쿼리당 최대 `O(n log n)`의 시간이 소요될 수 있습니다. `m`개의 쿼리가 있으므로, 전체 시간 복잡도는 `O(m * n log n)`입니다.
- **공간 복잡도**: 각 쿼리 처리 시 서브어레이의 복사본을 저장하기 위해 `O(n)`의 공간이 필요합니다. 따라서 공간 복잡도는 `O(n)`입니다.
*/
