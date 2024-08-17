class Solution 
{
public:
    vector<int> maxSubsequence(const vector<int>& nums, const int k) 
    {
        const size_t LENGTH = nums.size();
        vector<pair<int, int>> indexedNums;
        vector<int> result;

        

        for (size_t i = 0; i < LENGTH; ++i)
        {
            indexedNums.push_back({nums[i], i});
        }

        sort(indexedNums.begin(), indexedNums.end(), greater<pair<int, int>>());
        vector<pair<int, int>> topValuesK(indexedNums.begin(), indexedNums.begin() + k);

        sort(topValuesK.begin(), topValuesK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        for (const auto& elem : topValuesK)
        {
            result.push_back(elem.first);
        }

        return result;
    }
};

// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

/*

다음은 LeetCode 문제 2099번의 한국어 번역입니다:

---

### 2099. 가장 큰 합을 가진 길이 k의 부분 수열 찾기

**난이도: 쉬움**

#### 문제 설명

정수 배열 `nums`와 정수 `k`가 주어집니다. `nums`에서 길이 `k`의 부분 수열 중 가장 큰 합을 가진 부분 수열을 찾고자 합니다.

이러한 부분 수열을 정수 배열 형태로 반환하세요.

부분 수열이란 다른 배열에서 일부 또는 모든 요소를 순서를 바꾸지 않고 삭제하여 얻을 수 있는 배열을 의미합니다.

#### 예제

**예제 1**:
- 입력: `nums = [2,1,3,3]`, `k = 2`
- 출력: `[3,3]`
- 설명: 이 부분 수열은 3 + 3 = 6으로 가장 큰 합을 가집니다.

**예제 2**:
- 입력: `nums = [-1,-2,3,4]`, `k = 3`
- 출력: `[-1,3,4]`
- 설명: 이 부분 수열은 -1 + 3 + 4 = 6으로 가장 큰 합을 가집니다.

**예제 3**:
- 입력: `nums = [3,4,3,3]`, `k = 2`
- 출력: `[3,4]`
- 설명: 이 부분 수열은 3 + 4 = 7로 가장 큰 합을 가집니다. [4, 3]도 가능한 답입니다.

#### 제약 조건

- `1 <= nums.length <= 1000`
- `-105 <= nums[i] <= 105`
- `1 <= k <= nums.length`

---

*/
