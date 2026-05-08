class Solution
{
public:
    vector<int> countOppositeParity(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= static_cast<int>(nums.size()) && static_cast<int>(nums.size()) <= MAX_LENGTH);

        const size_t numsLength = nums.size();
        vector<int> parityNums(0, numsLength);
        vector<int> result(0, numsLength);
        
        for (const int num : nums) // 각 원소를 홀짝 여부로 변환
        {
            assert(MIN_VALUE <= num && num <= MAX_VALUE);
            parityNums.push_back((num % 2 == 0) ? EVEN : ODD);
        }

        for (size_t i = 0; i < numsLength; ++i)
        {
            int count = 0;
            for (size_t j = i + 1; j < numsLength; ++j)
            {
                if (parityNums[i] != parityNums[j])
                {
                    ++count;
                }
            }
            result.push_back(count);
        }

        assert(result.size() == numsLength);
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_VALUE  = 1,
        MAX_VALUE  = 100,
        EVEN       = 0,
        ODD        = 1,
    };
};

/*
https://leetcode.com/problems/count-indices-with-opposite-parity/description/ 
**3917. 반대 홀짝성을 가진 인덱스 개수 세기**

길이가 `n`인 정수 배열 `nums`가 주어집니다.

인덱스 `i`의 **점수**는 아래 조건을 만족하는 인덱스 `j`의 개수로 정의됩니다:

- `i < j < n` 이고
- `nums[i]`와 `nums[j]`의 **홀짝성이 다를 것** (하나는 짝수, 다른 하나는 홀수)

길이 `n`인 정수 배열 `answer`를 반환하세요. `answer[i]`는 인덱스 `i`의 점수입니다.

---

**예시 1**
- 입력: `nums = [1,2,3,4]`
- 출력: `[2,1,1,0]`
- 설명:

| 인덱스 i | nums[i] | 조건 만족하는 j | 점수 |
|---------|---------|--------------|------|
| 0 | 1 (홀수) | j=1(짝수), j=3(짝수) | 2 |
| 1 | 2 (짝수) | j=2(홀수) | 1 |
| 2 | 3 (홀수) | j=3(짝수) | 1 |
| 3 | 4 (짝수) | 없음 | 0 |

**예시 2**
- 입력: `nums = [1]`
- 출력: `[0]`
- 설명: 원소가 하나뿐이라 조건을 만족하는 `j`가 없음 → 점수 0

---

**제약 조건**
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

---

## 요약

각 인덱스 `i`에서 **오른쪽(`i+1 ~ n-1`)에 있는 원소 중 홀짝성이 다른 원소의 개수**를 세어 반환.

---

## 풀이 방향

**브루트포스 O(n²):**
1. 각 `i`에 대해 `j = i+1` 부터 `n-1` 까지 순회
2. `nums[i] % 2 != nums[j] % 2` 이면 카운트 증가
3. 카운트를 `answer[i]` 에 저장

*/
