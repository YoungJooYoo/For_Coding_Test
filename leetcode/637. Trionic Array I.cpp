class Solution
{
public:
    bool isTrionic(const vector<int>& nums) const
    {
        const size_t LENGTH = nums.size();
        assert(MIN_LEN <= LENGTH && LENGTH <= MAX_LEN);

        if (LENGTH < 4)
        {
            return false;
        }

        size_t pos = 0;
        size_t start = pos;

        while (pos + 1 < LENGTH && nums[pos] < nums[pos + 1])
        {
            ++pos;
        }
        if (pos == start)
        {
            return false;
        }

        start = pos;
        while (pos + 1 < LENGTH && nums[pos] > nums[pos + 1])
        {
            ++pos;
        }
        if (pos == start)
        {
            return false;
        }

        start = pos;
        while (pos + 1 < LENGTH && nums[pos] < nums[pos + 1])
        {
            ++pos;
        }
        if (pos == start)
        {
            return false;
        }

        return (pos == LENGTH - 1) ? true : false;
    }

private:
    enum
    {
        MIN_LEN = 3,
        MAX_LEN = 100,
        MIN_NUM = -1000,
        MAX_NUM = 1000
    };
};


// https://leetcode.com/problems/trionic-array-i/

/*

## 3637. 트라이오닉 배열 I

**난이도: 하**

---

### 문제 설명

정수 배열 `nums`가 주어집니다. 길이는 n입니다.

만약 배열에 인덱스 `0 < p < q < n-1`인 **두 지점**이 존재해서, 다음 세 구간이 각각

* `nums[0...p]`는 **엄격하게 증가(오름차순)**
* `nums[p...q]`는 **엄격하게 감소(내림차순)**
* `nums[q...n-1]`는 **엄격하게 증가(오름차순)**
  을 모두 만족한다면, 이 배열을 \*\*트라이오닉 배열(trionic array)\*\*이라고 부릅니다.

배열이 **트라이오닉 배열**이면 true, 아니면 false를 반환하세요.

---

### 예시

#### 예시 1

**입력:**
nums = \[1,3,5,4,2,6]

**출력:**
true

**설명:**
p = 2, q = 4로 잡으면

* nums\[0...2] = \[1, 3, 5] → **엄격하게 증가**
* nums\[2...4] = \[5, 4, 2] → **엄격하게 감소**
* nums\[4...5] = \[2, 6] → **엄격하게 증가**
  조건을 모두 만족하므로 true.

---

#### 예시 2

**입력:**
nums = \[2,1,3]

**출력:**
false

**설명:**
어떤 p, q를 골라도 조건을 만족하는 세 구간으로 나눌 수 없습니다.

---

### 제약사항

* 3 <= n <= 100
* -1000 <= nums\[i] <= 1000

---

### 힌트

* 완전탐색(brute force)로 풀 수 있음

---

더 궁금한 점, 코드, 풀이 등 필요하시면 말씀해 주세요!
*/
