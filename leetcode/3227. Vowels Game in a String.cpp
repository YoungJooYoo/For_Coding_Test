class Solution
{
public:
    bool doesAliceWin(string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);
        const size_t vowelCount = getLowercaseVowelCount(s);
        return (vowelCount > 0) ? true : false;
    }

private:
    size_t getLowercaseVowelCount(const string& s) const
    {
        size_t count = 0;

        for (const char ch : s)
        {
            assert('a' <= ch && ch <= 'z');
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' == true)
            {
                ++count;
            }
        }

        return count;
    }

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000
    };
};


// https://leetcode.com/problems/vowels-game-in-a-string/description/?envType=daily-question&envId=2025-09-12

/*


## 3227. 문자열 속 모음 게임 (Vowels Game in a String)

Alice와 Bob은 문자열을 가지고 게임을 합니다.

문자열 `s`가 주어졌을 때, Alice와 Bob은 번갈아가며 다음 규칙에 따라 게임을 진행합니다. 

Alice가 먼저 시작합니다:

* **Alice의 차례**: `s`에서 **모음 개수가 홀수**인, 
비어 있지 않은 부분 문자열(substring)을 하나 골라서 제거해야 합니다.

* **Bob의 차례**: `s`에서 **모음 개수가 짝수**인, 
비어 있지 않은 부분 문자열을 하나 골라서 제거해야 합니다.

* 자기 차례에 가능한 부분 문자열이 없으면 그 플레이어는 게임에서 집니다.

두 사람은 \*\*항상 최적의 전략(optimal play)\*\*으로 플레이한다고 가정합니다.
문자열 `s`가 주어질 때, **Alice가 이기는 경우 true, 그렇지 않으면 false**를 반환하세요.

영어 모음은 다음 다섯 개입니다: `a, e, i, o, u`.

---

### 예시 1

입력:

```
s = "leetcoder"
```

출력:

```
true
```

설명:

* 1턴(Alice): `"lee"`(모음 3개)와 같은 부분 문자열을 제거해서 `"der"`가 남음
* 2턴(Bob): `"d"`(모음 0개) 같은 부분 문자열 제거해서 `"er"`가 남음
* 3턴(Alice): `"er"` 전체(모음 1개)를 제거 → 문자열은 빈 문자열이 됨
* 4턴(Bob): 빈 문자열이므로 더 이상 제거할 부분 문자열이 없음 → Bob 패배

따라서 Alice가 승리합니다.

---

### 예시 2

입력:

```
s = "bbcd"
```

출력:

```
false
```

설명:

* Alice 차례인데, `s`에서 모음이 하나도 없으므로 (홀수 개 모음이 포함된 부분 문자열이 없음) Alice는 곧바로 패배합니다.

---

### 제약 조건

* `1 <= s.length <= 10^5`
* `s`는 오직 소문자 영어 알파벳으로만 이루어져 있습니다.

---

*/
