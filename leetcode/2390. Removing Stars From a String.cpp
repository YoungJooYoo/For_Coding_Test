class Solution
{
public:
    string removeStars(const string& s) const
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        stack<char> charStack;

        for (const char currChar : s)
        {
            assert(('a' <= currChar && currChar <= 'z') || currChar == '*');
            if (currChar == '*')
            {
                assert(!charStack.empty());
                charStack.pop();
            }
            else
            {
                charStack.push(currChar);
            }
        }

        string output;
        while (!charStack.empty())
        {
            output.push_back(charStack.top());
            charStack.pop();
        }

        ranges::reverse(output);
        return output;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
    };
};

// https://leetcode.com/problems/removing-stars-from-a-string/

/*
다음은 한국어 번역입니다.

# 2390. 문자열에서 별 지우기 (Removing Stars From a String)

문자열 `s`가 주어지며, 이 문자열에는 별표 `*`가 포함되어 있습니다.

한 번의 연산으로 다음을 수행할 수 있습니다:

1. `s`에서 임의의 `*` 하나를 선택한다.
2. 그 `*`의 **왼쪽에 있는 가장 가까운 `*`가 아닌 문자**를 제거하고, 동시에 그 `*`도 제거한다.

모든 `*`가 제거된 뒤의 문자열을 반환하세요.

**참고:**

* 입력은 위 연산을 **항상 수행할 수 있도록** 생성됩니다.
* 결과 문자열은 **항상 유일함**을 보일 수 있습니다.

---

## 예시 1

**입력:** `s = "leet**cod*e"`
**출력:** `"lecoe"`

**설명(왼쪽에서 오른쪽으로 제거):**

* 첫 번째 `*`의 왼쪽에서 가장 가까운 문자는 `'t'` → `"lee*cod*e"`
* 두 번째 `*`의 왼쪽에서 가장 가까운 문자는 `'e'` → `"lecod*e"`
* 세 번째 `*`의 왼쪽에서 가장 가까운 문자는 `'d'` → `"lecoe"`
  더 이상 `*`가 없으므로 `"lecoe"`를 반환합니다.

---

## 예시 2

**입력:** `s = "erase*****"`
**출력:** `""`

**설명:** 문자열 전체가 제거되어 빈 문자열을 반환합니다.

---

## 제약 조건

* `1 <= s.length <= 10^5`
* `s`는 **소문자 영어 알파벳**과 \*\*별표 `*`\*\*로만 구성됩니다.
* 위의 연산을 `s`에 대해 항상 수행할 수 있습니다.

*/
