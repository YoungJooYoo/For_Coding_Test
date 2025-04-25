class Solution 
{
public:
    int nthSuperUglyNumber(const int n, const vector<int>& primes) const
    {
        const int k = primes.size();
        vector<long long> nextVal(primes.begin(), primes.end());
        vector<int> idx(k, 0);
        vector<int> ugly(n);

        assert(n >= MIN_N && n <= MAX_N);
        assert(k >= MIN_K && k <= MAX_K);
        
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) 
        {
            long long mn = nextVal[0];
            for (int j = 1; j < k; ++j) 
            {
                mn = min(mn, nextVal[j]);
            }
            ugly[i] = static_cast<int>(mn);
            for (int j = 0; j < k; ++j) 
            {
                if (nextVal[j] == mn) 
                {
                    ++idx[j];
                    nextVal[j] = static_cast<long long>(ugly[idx[j]]) * primes[j];
                }
            }
        }
        
        return ugly[n - 1];
    }

private:
    enum 
    {
        MIN_N        = 1,
        MAX_N        = 100000,
        MIN_K        = 1,
        MAX_K        = 100,
        MIN_PRIME    = 2,
        MAX_PRIME    = 1000
    };
};

// https://leetcode.com/problems/super-ugly-number/description/

/*
**313. 슈퍼 얼기 숫자 (Super Ugly Number)**

**난이도:** 중간

**문제 설명:**  
슈퍼 얼기 숫자(super ugly number)란, 그 수의 모든 소인수가 주어진 배열 **primes**에만 포함되는 양의 정수를 말합니다.

정수 `n`과 소수 배열 `primes`가 주어질 때, **n번째 슈퍼 얼기 숫자**를 반환하세요.  
여기서 1번째 슈퍼 얼기 숫자는 1로 정의하며, 이후 차례대로 올림차순으로 나열된 수들입니다.

---

**예제 1:**

- **입력:** n = 12, primes = [2,7,13,19]  
- **출력:** 32  
- **설명:**  
  주어진 소수집합 `[2,7,13,19]`으로 만들 수 있는 슈퍼 얼기 숫자는  
  `1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32, …`  
  이고, 이 중 12번째가 32입니다.

---

**예제 2:**

- **입력:** n = 1, primes = [2,3,5]  
- **출력:** 1  
- **설명:**  
  1은 소인수가 없으므로 소인수들이 모두 `primes` 안에 있다고 간주하여 1번째 슈퍼 얼기 숫자는 1입니다.

---

**제약 조건:**

- 1 ≤ n ≤ 10^5  
- 1 ≤ primes.length ≤ 100  
- 2 ≤ primes[i] ≤ 1000  
- `primes[i]`는 소수이며, 배열 내 값들은 중복 없이 오름차순으로 정렬되어 있습니다.
*/
