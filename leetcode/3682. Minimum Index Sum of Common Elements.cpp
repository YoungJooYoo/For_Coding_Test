class Solution
{
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) const
    {
        assert(nums1.size() == nums2.size());
        assert(nums1.size() >= static_cast<size_t>(MIN_LENGTH) && nums1.size() <= static_cast<size_t>(MAX_LENGTH));

        unordered_map<int, size_t> firstPos;
        int best = numeric_limits<int>::max();

        for (size_t i = 0; i < nums1.size(); ++i)
        {
            assert(nums1[i] >= MIN_NUM && nums1[i] <= MAX_NUM);
            assert(nums2[i] >= MIN_NUM && nums2[i] <= MAX_NUM);
            if (firstPos.find(nums1[i]) == firstPos.end())
            {
                firstPos[nums1[i]] = i;
            }
        }

        for (size_t j = 0; j < nums2.size(); ++j)
        {
            const auto& it = firstPos.find(nums2[j]);
            if (it != firstPos.end())
            {
                const int candidate = static_cast<int>(it->second + j);
                best = min(best, candidate);
            }
        }

        return (best == numeric_limits<int>::max()) ? FAIL : best;
    }

private:
    enum
    {
        FAIL = -1,
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_NUM = -100000,
        MAX_NUM = 100000
    };
};

// https://leetcode.com/problems/minimum-index-sum-of-common-elements/description/

/*


# 3682. 공통 원소의 최소 인덱스 합 (Minimum Index Sum of Common Elements)

길이가 같은 두 정수 배열 `nums1`과 `nums2`가 주어집니다. 두 배열의 길이는 `n`입니다.

인덱스 쌍 `(i, j)`에 대해, 만약 `nums1[i] == nums2[j]`라면 이 쌍을 **좋은 쌍(good pair)** 이라고 정의합니다.

모든 좋은 쌍 중에서 **인덱스 합 `i + j`의 최솟값**을 반환하세요.
만약 좋은 쌍이 하나도 없다면 `-1`을 반환하세요.

---

## 예시 1

**입력:** `nums1 = [3,2,1]`, `nums2 = [1,3,1]`
**출력:** `1`

**설명:**
`nums1`과 `nums2`의 공통 원소는 `1`과 `3`입니다.

* 원소 `3`: `[i, j] = [0, 1]` → 인덱스 합 `i + j = 1`
* 원소 `1`: `[i, j] = [2, 0]` → 인덱스 합 `i + j = 2`
  따라서 최소 인덱스 합은 `1`입니다.

---

## 예시 2

**입력:** `nums1 = [5,1,2]`, `nums2 = [2,1,3]`
**출력:** `2`

**설명:**
공통 원소는 `1`과 `2`입니다.

* 원소 `1`: `[i, j] = [1, 1]` → `i + j = 2`
* 원소 `2`: `[i, j] = [2, 0]` → `i + j = 2`
  최소 인덱스 합은 `2`입니다.

---

## 예시 3

**입력:** `nums1 = [6,4]`, `nums2 = [7,8]`
**출력:** `-1`

**설명:**
공통 원소가 없으므로 `-1`을 반환합니다.

---

## 제약 조건

* `1 <= nums1.length == nums2.length <= 10^5`
* `-10^5 <= nums1[i], nums2[i] <= 10^5`

---

## 힌트

1. `nums1`의 각 값에 대해 **가장 작은 등장 인덱스**를 저장하는 해시맵 `pos1`을 만드세요.
2. `nums2`를 순회하면서 각 인덱스 `j`에 대해 `nums2[j]`가 `pos1`에 존재하면 `pos1[nums2[j]] + j`를 계산하세요.
3. 위와 같은 매칭들 중 **최소 인덱스 합**을 추적하세요.
4. 공통 원소가 하나도 없으면 `-1`을 반환하세요.

*/
