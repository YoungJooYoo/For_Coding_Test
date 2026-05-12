class Solution
{
public:
    vector<int> concatWithReverse(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);
        
        vector<int> result(nums);
        result.insert(result.end(), nums.rbegin(), nums.rend());

        assert(static_cast<int>(result.size()) == static_cast<int>(nums.size()) * 2);
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 1,
        MAX_VALUE  = 100,
    };
};
/*
https://leetcode.com/problems/concatenate-array-with-reverse/description/
## 문제 번역

**3925. 배열과 역순 배열 이어 붙이기**

길이가 `n`인 정수 배열 `nums`가 주어집니다.

길이가 `2 * n`인 새 배열 `ans`를 만드세요:
- 앞쪽 `n`개 → `nums` 그대로
- 뒤쪽 `n`개 → `nums`를 **역순**으로

공식으로 표현하면 (`0 <= i <= n-1`):
- `ans[i] = nums[i]`
- `ans[i + n] = nums[n - i - 1]`

배열 `ans`를 반환하세요.

---

**예시 1**
- 입력: `nums = [1,2,3]`
- 출력: `[1,2,3,3,2,1]`
- 설명:
  - 앞쪽: `[1,2,3]` 그대로
  - 뒤쪽: `[3,2,1]` 역순
  - 결과: `[1,2,3,3,2,1]`

**예시 2**
- 입력: `nums = [1]`
- 출력: `[1,1]`
- 설명: 원소가 하나라 역순도 동일

---

**제약 조건**
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

---

## 요약

`nums` 뒤에 `nums`의 역순을 이어 붙인 배열 반환.

---

## 풀이 방향

```cpp
// ans = nums 복사
// ans 뒤에 nums를 역순으로 삽입
ans.insert(ans.end(), nums.rbegin(), nums.rend());
```

*/
