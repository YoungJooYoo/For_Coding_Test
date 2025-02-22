class Solution 
{
public:
    long long minEnd(const int n, const int x)
    {
        assert(n >= MIN_N && n <= MAX_N);
        assert(x >= MIN_X && x <= MAX_X);
        
        const int v = n - 1; // v는 배열 길이에서 1을 뺀 값입니다. (병합할 값)
        unsigned long long mergedResult = x;  // mergedResult는 초기 값 x에서 시작하며, 여기에 v의 비트를 병합합니다.
        
        // mask는 v의 각 비트 위치를 확인하기 위한 변수입니다.
        // candidateMask는 x에서 0인 비트 자리에 채워 넣을 후보 비트를 나타냅니다.
        for (unsigned long long mask = 1, candidateMask = 1; mask <= static_cast<unsigned long long>(v); mask <<= 1, candidateMask <<= 1)
        {
            // 만약 candidateMask가 이미 mergedResult에 설정되어 있다면,
            // 후보 비트가 다른 자리로 이동하도록 조정합니다.
            while (candidateMask & mergedResult)
            {
                candidateMask <<= 1;
            }
                       
            if (v & mask) // 만약 v의 해당 비트가 1이면, mergedResult에 candidateMask 비트를 설정합니다.
            {
                mergedResult |= candidateMask;
            }
        }
        
        return mergedResult;
    }
    
private:
    enum 
    {
        MIN_N = 1,
        MAX_N = 100000000,  // 10^8
        MIN_X = 1,
        MAX_X = 100000000   // x에 대한 상한 (문제에 따라 조정 가능)
    };
};


// https://leetcode.com/problems/minimum-array-end/description/


/*
다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**3133. 최소 배열 끝 값**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

정수 **n**과 **x**가 주어집니다.  
양의 정수로 구성된 크기 **n**의 배열 **nums**를 구성해야 합니다. 이때, 모든 0 ≤ i < n - 1에 대해 **nums[i + 1]**는 **nums[i]**보다 커야 하며, **nums**의 모든 원소에 대해 비트 AND 연산을 수행한 결과가 **x**가 되어야 합니다.

이 조건을 만족하는 **nums[n - 1]**의 가능한 최소 값을 반환하세요.

---

**예제 1:**

```
입력: n = 3, x = 4
출력: 6
```

*설명:*  
예를 들어, **nums**를 [4, 5, 6]으로 구성할 수 있으며, 마지막 원소는 6입니다.

---

**예제 2:**

```
입력: n = 2, x = 7
출력: 15
```

*설명:*  
예를 들어, **nums**를 [7, 15]로 구성할 수 있으며, 마지막 원소는 15입니다.

---

**제약 조건:**

- 1 <= n, x <= 10^8

---

**힌트 1:**  
배열의 각 원소는 v = 0, 1, 2, …, (n - 1)과 **x**를 "병합(merge)"하여 얻어야 합니다.

**힌트 2:**  
**x**와 다른 숫자 v를 병합할 때, **x**의 설정된 비트는 그대로 유지하고, 나머지 비트들에 대해서는 v의 설정된 비트들을 오른쪽부터 차례로 채워 넣습니다.

**힌트 3:**  
따라서, 최종 답은 **x**와 (n - 1)을 병합한 결과가 됩니다.
*/
