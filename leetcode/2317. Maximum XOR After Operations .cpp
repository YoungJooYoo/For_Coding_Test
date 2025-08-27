class Solution
{
public:
    int maximumXOR(const vector<int>& nums) const
    {
        const size_t length = nums.size();
        int result = 0;

        assert(MIN_LENGTH <= length && length <= MAX_LENGTH);

        for (const int value : nums)
        {
            assert(MIN_VALUE <= value && value <= MAX_VALUE);
            result |= value;
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,   // 1 <= nums.length <= 1e5
        MIN_VALUE  = 0,
        MAX_VALUE  = 100000000 // 0 <= nums[i] <= 1e8
    };
};


// https://leetcode.com/problems/maximum-xor-after-operations/description/

/*



## 2317. 연산 후의 최대 XOR 값

**난이도:** Medium

### 문제 설명

0-인덱스 정수 배열 `nums`가 주어집니다.

한 번의 연산에서 다음을 수행할 수 있습니다:

* 임의의 **음이 아닌 정수** `x`와 인덱스 `i`를 선택한다.
* 그런 다음 `nums[i]`를 `nums[i] AND (nums[i] XOR x)`로 갱신한다.

여기서 `AND`는 비트 단위 AND 연산, `XOR`은 비트 단위 XOR 연산입니다.

이 연산을 원하는 횟수만큼 수행할 수 있을 때, **모든 원소의 비트 단위 XOR 값의 최댓값**을 반환하세요.

---

### 예제 1

**입력:**

```
nums = [3,2,4,6]
```

**출력:**

```
7
```

**설명:**

* 연산을 `x = 4`, `i = 3`으로 수행한다고 가정하면:
  `nums[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2`
* 따라서 `nums = [3,2,4,2]`가 되고,
  `3 XOR 2 XOR 4 XOR 2 = 7`
* 7이 가능한 최대 XOR 값임을 증명할 수 있습니다.
* 다른 방법으로도 XOR = 7을 만들 수 있습니다.

---

### 예제 2

**입력:**

```
nums = [1,2,3,9,2]
```

**출력:**

```
11
```

**설명:**

* 연산을 아예 수행하지 않아도 됩니다.
* `1 XOR 2 XOR 3 XOR 9 XOR 2 = 11`
* 이것이 가능한 최대 XOR 값입니다.

---

### 제약 조건

* `1 <= nums.length <= 10^5`
* `0 <= nums[i] <= 10^8`

---

*/
