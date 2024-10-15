class Solution 
{
public:
    vector<int> findXSum(const vector<int>& nums, const int k, const int x) 
    {
        const size_t LENGTH = nums.size();
        vector<int> result;
        

        for (size_t i = 0; i < LENGTH - k + 1; ++i)
        {
            map<int, int, greater<int>> freq;
            for (size_t j = i; j < k + i; ++j)
            {
                ++freq[nums[j]];
            }
            // 빈도수 내림차순, 값 내림차순으로 정렬하기 위해 벡터로 변환
            vector<pair<int, int>> freqVec(freq.begin(), freq.end());
            sort(freqVec.begin(), freqVec.end(), [&](const pair<int, int>& a, const pair<int, int>& b) -> bool 
            {
                if (a.second != b.second) 
                {
                    return a.second > b.second; // 빈도수 내림차순
                }
                return a.first > b.first; // 값 내림차순
            });

            // 상위 x 요소의 합 계산
            int sum = 0;
            for (int k = 0; k < x && k < freqVec.size(); ++k)
            {
                sum += freqVec[k].first * freqVec[k].second;
            }

            result.push_back(sum);
        }

        return result;
    }
};

// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/

/*


### 3318. 모든 길이가 K인 부분 배열의 X-합 찾기 I


주어진 `n`개의 정수로 이루어진 배열 `nums`와 두 정수 `k`와 `x`가 주어집니다.

배열의 **X-합**은 다음 절차에 따라 계산됩니다:

1. 배열 내 모든 요소의 발생 횟수를 셉니다.
2. 가장 빈번하게 등장하는 상위 `x`개의 요소만 유지합니다. 만약 두 요소의 발생 횟수가 동일하다면, 더 큰 값을 가진 요소가 더 빈번하게 등장한 것으로 간주됩니다.
3. 결과 배열의 합을 계산합니다.

만약 배열에 서로 다른 요소가 `x`개 미만이라면, 해당 배열의 X-합은 배열의 모든 요소의 합과 동일합니다.

길이가 `n - k + 1`인 정수 배열 `answer`를 반환하세요. 여기서 `answer[i]`는 부분 배열 `nums[i..i + k - 1]`의 X-합입니다.

#### 예제 1:

```
입력: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
출력: [6,10,12]
```

**설명:**

1. 부분 배열 `[1, 1, 2, 2, 3, 4]`의 경우, 가장 빈번하게 등장하는 두 요소는 `1`과 `2`입니다. 따라서 결과 배열에는 `1`과 `2`만 유지됩니다. 따라서 `answer[0] = 1 + 1 + 2 + 2 = 6`입니다.
2. 부분 배열 `[1, 2, 2, 3, 4, 2]`의 경우, 가장 빈번하게 등장하는 두 요소는 `2`와 `4`입니다. `4`는 `3`과 `1`이 동일한 빈도로 등장하지만 더 큰 값이므로 유지됩니다. 따라서 `answer[1] = 2 + 2 + 2 + 4 = 10`입니다.
3. 부분 배열 `[2, 2, 3, 4, 2, 3]`의 경우, 가장 빈번하게 등장하는 두 요소는 `2`와 `3`입니다. 따라서 `answer[2] = 2 + 2 + 2 + 3 + 3 = 12`입니다.

#### 예제 2:

```
입력: nums = [3,8,7,8,7,5], k = 2, x = 2
출력: [11,15,15,15,12]
```

**설명:**

`k == x`인 경우, `answer[i]`는 부분 배열 `nums[i..i + k - 1]`의 합과 동일합니다. 따라서 각 부분 배열의 합이 바로 X-합이 됩니다.

---

#### 제약 사항:

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= k <= nums.length`
- `1 <= x <= nums.length`

---

도움이 되었기를 바랍니다! 추가로 번역이 필요한 문제나 다른 질문이 있으시면 언제든지 말씀해주세요.
*/
