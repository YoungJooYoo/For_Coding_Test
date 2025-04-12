class Solution {
public:
    int monkeyMove(const int n) const
    {
        assert(n >= MIN_N && n <= MAX_N);
        const long long totalWays = modPow(2LL, n, MOD);
        const long long ans = (totalWays - 2 + MOD) % MOD;
        return static_cast<int>(ans);
    }
    
private:
    long long modPow(long long base, long long exp, const long long mod) const 
    {
        long long result = 1;
        base %= mod;

        while (exp > 0) 
        {
            if (exp & 1) 
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    enum 
    {
        MOD = 1000000007,
        MIN_N = 3,
        MAX_N = 1000000000
    };
};

// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/?envType=problem-list-v2&envId=recursion

/*


---

**2550. 다각형에서 원숭이 충돌 횟수 구하기**

**난이도:** 중간

**문제 설명:**  
n개의 정점으로 이루어진 정규 볼록 다각형이 있습니다.  
정점들은 시계 방향으로 0부터 n - 1까지 번호가 매겨져 있으며, 각 정점에는 원숭이가 한 마리씩 있습니다. (아래 그림은 6개의 정점을 가진 볼록 다각형을 보여줍니다.)

동시에, 각 원숭이는 인접한 정점으로 이동합니다.  
이 때, 충돌(collision)은 다음 두 가지 경우 중 하나가 발생하면 일어납니다:
- 이동 후에 두 마리 이상의 원숭이가 같은 정점에 있게 되는 경우.
- 이동 중에 원숭이들이 어떤 간선을 따라 교차하는 경우.

최소 한 번 이상의 충돌이 발생하도록 원숭이들이 이동할 수 있는 방법의 수를 반환하세요.  
답이 매우 클 수 있으므로, 10^9 + 7로 나눈 나머지를 반환합니다.

---

**예제 1:**

- **입력:** n = 3  
- **출력:** 6  
- **설명:**  
  가능한 이동 방법은 총 8가지입니다.  
  예를 들어, 충돌이 발생하는 두 가지 경우는 다음과 같습니다:  
  - 원숭이 1은 시계 방향, 원숭이 2는 반시계 방향, 원숭이 3은 시계 방향으로 이동하는 경우 → 이때 원숭이 1과 2가 충돌합니다.  
  - 원숭이 1은 반시계 방향, 원숭이 2는 반시계 방향, 원숭이 3은 시계 방향으로 이동하는 경우 → 이때 원숭이 1과 3이 충돌합니다.

---

**예제 2:**

- **입력:** n = 4  
- **출력:** 14

---

**제약 조건:**

- 3 <= n <= 10^9

---
*/
