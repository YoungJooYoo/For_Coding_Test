class Solution
{
public:
    int minSwaps(const string& s) const
    {
        const size_t n = s.size();
        int openCount = 0;
        int openTotal = 0;
        int swaps = 0;

        assert(MIN_LEN <= n && n <= MAX_LEN);
        assert(n % 2 == 0);

        for (const char ch : s)
        {
            assert(ch == OPEN || ch == CLOSE);
            if (ch == OPEN)
            {
                ++openTotal;
                ++openCount;
            }
            else // ch == CLOSE
            {
                if (openCount > 0)
                {
                    --openCount; // 바로 매칭 가능
                }
                else
                {
                    ++swaps; // 왼쪽에 매칭할 '['가 없으므로, 뒤쪽의 '[' 하나와 스왑 필요
                    openCount = 1; // 스왑으로 현재 위치가 '['가 되어 매칭 대기 상태
                }
            }
        }

        assert(openTotal * 2 == static_cast<int>(n)); // 여는/닫는 괄호 수 동일
        assert(swaps >= 0);
        
        return swaps;
    }

private:
    enum
    {
        MIN_LEN = 2,
        MAX_LEN = 1000000,
        OPEN = '[',
        CLOSE = ']'
    };
};

// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

/*

다음은 **1963. Minimum Number of Swaps to Make the String Balanced** 문제의 국문 번역입니다.

---

## 1963. 문자열을 균형 있게 만들기 위한 최소 스왑 횟수

**난이도:** 중간

---

### 문제 설명

길이가 **짝수**인 0-인덱스 문자열 `s`가 주어집니다.
문자열 `s`는 정확히 절반(`n / 2`)은 여는 괄호 `'['`, 나머지 절반(`n / 2`)은 닫는 괄호 `']'`로 이루어져 있습니다.

문자열이 **균형 잡힌 문자열(balanced)** 이라고 부르는 조건은 다음 중 하나를 만족하는 경우입니다.

1. 빈 문자열
2. 문자열을 `A + B` 형태로 표현할 수 있고, 여기서 `A`와 `B` 모두 균형 잡힌 문자열
3. 문자열을 `'[' + C + ']'` 형태로 표현할 수 있고, 여기서 `C`가 균형 잡힌 문자열

당신은 **아무 인덱스의 괄호 두 개를 선택해서 서로 교환(swap)** 할 수 있습니다.
이 과정을 원하는 만큼 반복할 수 있습니다.

문자열을 균형 잡힌 문자열로 만들기 위한 **최소 스왑 횟수**를 반환하세요.

---

### 예시

#### 예시 1

```
입력: s = "][]["
출력: 1
설명:
인덱스 0과 인덱스 3을 교환하면 "[[]]"가 되어 균형을 이룹니다.
```

#### 예시 2

```
입력: s = "]]][[["
출력: 2
설명:
다음과 같이 교환합니다:
- 인덱스 0 ↔ 인덱스 4: s = "[]][]["
- 인덱스 1 ↔ 인덱스 5: s = "[[][]]"
결과적으로 "[[][]]"가 되어 균형을 이룹니다.
```

#### 예시 3

```
입력: s = "[]"
출력: 0
설명:
이미 균형 잡힌 상태입니다.
```

---

### 제약 조건

* `n == s.length`
* `2 <= n <= 10^6`
* `n`은 짝수
* `s[i]`는 `'['` 또는 `']'`
* `'['`의 개수는 `n / 2`, `']'`의 개수도 `n / 2`

---

### 힌트

1. 문자열을 순회하며 각 단계에서 여는 괄호와 닫는 괄호 개수를 추적합니다.
2. 만약 닫는 괄호 개수가 더 많아진 순간이 있다면, 스왑이 필요합니다.
3. 이때 가능한 한 문자열 끝 쪽에 가까운 여는 괄호와 교환하는 것이 좋습니다.

---

원하시면 제가 이 문제의 **POCU 스타일 최적 코드**로도 바로 구현해 드릴 수 있습니다.
이 문제는 \*\*O(n)\*\*에 풀 수 있고, 스택 없이 카운팅만으로 해결 가능합니다.

*/
