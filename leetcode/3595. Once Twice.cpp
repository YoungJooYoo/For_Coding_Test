class Solution
{
public:
    vector<int> onceTwice(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        vector<int> result(2, 0);
        unordered_map<int, int> freq;

        for (const auto& num : nums)
        {
            ++freq[num];
        }

        for (const auto [num, count] : freq)
        {
            if (count == 1)
            {
                result[0] = num;
            }
            else if (count ==2)
            {
                result[1] = num;
            }
        }

        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 3,
        MAX_LENGTH = 100000,
    };
};

// https://leetcode.com/problems/once-twice/description/

/*


---

## 3595. 한 번과 두 번 (Once Twice)

### 문제 설명

정수 배열 `nums`가 주어집니다. 이 배열에는 다음 조건이 항상 성립합니다:

* 정확히 하나의 원소는 **한 번만 등장**합니다.
* 정확히 하나의 원소는 **두 번 등장**합니다.
* 나머지 모든 원소는 **세 번씩 등장**합니다.

이때, 길이 2인 정수 배열을 반환하세요.

* 첫 번째 원소는 한 번 등장하는 값,
* 두 번째 원소는 두 번 등장하는 값입니다.

**해결 조건**:

* 시간 복잡도는 `O(n)`
* 공간 복잡도는 `O(1)`

---

### 예제 1

**입력**:

```
nums = [2,2,3,2,5,5,5,7,7]
```

**출력**:

```
[3,7]
```

**설명**:

* 원소 `3`은 한 번 등장,
* 원소 `7`은 두 번 등장,
* 나머지 (`2`, `5`)는 각각 세 번 등장.

---

### 예제 2

**입력**:

```
nums = [4,4,6,4,9,9,9,6,8]
```

**출력**:

```
[8,6]
```

**설명**:

* 원소 `8`은 한 번 등장,
* 원소 `6`은 두 번 등장,
* 나머지 (`4`, `9`)는 각각 세 번 등장.

---

### 제약 조건

* `3 <= nums.length <= 100,000`
* `-2^31 <= nums[i] <= 2^31 - 1`
* `nums.length`는 3의 배수이다.
* 정확히 한 원소는 한 번, 한 원소는 두 번, 나머지는 세 번씩 등장한다.

---


*/
