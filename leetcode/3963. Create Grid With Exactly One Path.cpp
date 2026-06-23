class Solution
{
public:
    vector<string> createGrid(const int m, const int n) const
    {
        assert(MIN_SIZE <= m && m <= MAX_SIZE);
        assert(MIN_SIZE <= n && n <= MAX_SIZE);

        vector<string> result(m, string(n, '#'));
        const int diagLength = min(m, n);

        for (size_t i = 0; i < static_cast<size_t>(diagLength); ++i)
        {
            result[i][i] = '.';
            if (i + 1 < n)
            {
                result[i][i + 1] = '.';
            }
        }

        if (m < n)
        {
            for (size_t j = m; j < static_cast<size_t>(n); ++j)
            {
                result[m - 1][j] = '.';
            }
        }
        else if (m > n)
        {
            for (size_t i = n; i < static_cast<size_t>(m); ++i)
            {
                result[i][n - 1] = '.';
            }
        }

        assert(static_cast<int>(result.size()) == m);
        assert(static_cast<int>(result[0].size()) == n);

        return result;
    }

private:
    enum
    {
        MIN_SIZE = 1,
        MAX_SIZE = 25,
    };
};

/*

https://leetcode.com/problems/create-grid-with-exactly-one-path/description/
**3963. 정확히 하나의 경로를 가진 격자 만들기**

행의 수 `m`과 열의 수 `n`이 주어집니다.

`'.'`와 `'#'`으로만 이루어진 `m x n` 격자를 만드세요:
- `'.'` → 이동 가능한 빈 칸
- `'#'` → 장애물 칸

**유효한 경로**는 아래 조건을 만족하는 빈 칸들의 연속입니다:
- 왼쪽 상단 `(0, 0)` 에서 시작
- 오른쪽 하단 `(m-1, n-1)` 에서 종료
- 이동 방향은 **오른쪽** 또는 **아래**만 가능

**유효한 경로가 정확히 하나**인 격자를 반환하세요.

---

**예시 1**
- 입력: `m = 2`, `n = 3`
- 출력: `["..#", "#.."]`
- 설명: 유일한 경로 → `(0,0)→(0,1)→(1,1)→(1,2)`

```
. . #
# . .
```

**예시 2**
- 입력: `m = 3`, `n = 3`
- 출력: `["..#", "#..", "##."]`
- 설명: 유일한 경로 → `(0,0)→(0,1)→(1,1)→(1,2)→(2,2)`

```
. . #
# . .
# # .
```

**예시 3**
- 입력: `m = 1`, `n = 4`
- 출력: `["...."]`
- 설명: 유일한 경로 → `(0,0)→(0,1)→(0,2)→(0,3)`

```
. . . .
```

---

**제약 조건** (원문에 미기재, 일반적으로):
- `1 <= m, n <= 10^5`
- `2 <= m * n <= 10^5`

---

## 요약

경로가 **딱 하나만** 존재하도록 `'.'`과 `'#'`으로 격자를 구성해서 반환.

---

## 핵심 패턴 관찰

```
m=2, n=3:          m=3, n=3:
. . #              . . #
# . .              # . .
                   # # .
```

**패턴:**
- 각 행에서 **오른쪽으로 가다가 아래로 내려가는 지점**에서 꺾임
- 꺾이는 열 = 현재 행 번호
- 꺾이기 전 열은 `'.'`, 이후는 `'#'` / 다음 행은 반대

*/
