class Solution 
{
public:
    bool checkPrimeFrequency(vector<int>& nums) 
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        unordered_map<int, int> freq;

        for (const auto num : nums)
        {
            assert(MIN_NUM <= num && num <= MAX_NUM);
            ++freq[num];
        }
        
        for (const auto [num, count] : freq)
        {
            if (isPrime(count) == true)
            {
                return true;
            }
        }

        return false;
    }

private:
    bool isPrime(const int n) 
    {
        if (n == 1) return false;
        
        for (int i = 2; i < n; i++) 
        {
            if (n % i == 0) 
            {
                return false;
            }
        }

        return true;
    }

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUM = 0,
        MAX_NUM = 100,
    };
};

// https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/

/*

**문제 3591. 어떤 원소의 등장 횟수가 소수인지 확인하기**
쉬움

---

정수 배열 `nums`가 주어집니다.

배열에서 \*\*어떤 원소라도 등장 빈도(횟수)가 소수(prime number)\*\*라면 `true`를,
그렇지 않으면 `false`를 반환하세요.

* **등장 빈도**란, 배열 내에서 어떤 값이 몇 번 나타나는지를 의미합니다.
* **소수**란, 1과 자기 자신만을 약수로 갖는 1보다 큰 자연수입니다.

---

## 예시 1

```
입력: nums = [1,2,3,4,5,4]
출력: true
```

**설명:**

* 4는 배열에 2번 등장합니다.
* 2는 소수이므로, true.

---

## 예시 2

```
입력: nums = [1,2,3,4,5]
출력: false
```

**설명:**

* 모든 원소가 1번만 등장합니다.
* 1은 소수가 아니므로, false.

---

## 예시 3

```
입력: nums = [2,2,2,4,4]
출력: true
```

**설명:**

* 2는 3번, 4는 2번 등장합니다.
* 2와 3은 모두 소수이므로, true.

---

## 제약사항

* `1 ≤ nums.length ≤ 100`
* `0 ≤ nums[i] ≤ 100`

---

**힌트:**

* 등장 빈도를 구하고, 그 중 하나라도 소수(prime)이면 true를 반환하세요.


*/
