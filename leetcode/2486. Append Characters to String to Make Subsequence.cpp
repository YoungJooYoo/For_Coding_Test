class Solution
{
public:
    int appendCharacters(const string& s, const string& t)
    {
        size_t matchedLength = 0;
        const size_t targetLength = t.size();

        for (const char ch : s)
        {
            if (matchedLength == targetLength)
            {
                break;
            }
            else if (ch == t[matchedLength])
            {
                ++matchedLength;
            }
        }

        return static_cast<int>(targetLength - matchedLength);
    }
};

/*
https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

---

### **2486. 부분 수열을 만들기 위해 문자열에 문자 추가하기 (Append Characters to String to Make Subsequence)**

소문자 영문자로만 구성된 두 문자열 `s`와 `t`가 주어집니다.

`t`가 `s`의 **부분 수열(subsequence)**이 되도록 하기 위해, `s`의 끝에 추가해야 하는 **최소 문자 수**를 반환하십시오.

**부분 수열**이란 원래 문자열에서 나머지 문자의 순서를 바꾸지 않고 일부 문자를 삭제하거나(아예 삭제하지 않을 수도 있음) 해서 얻을 수 있는 문자열을 말합니다.

---

**예제 1:**

*   **입력:** `s = "coaching"`, `t = "coding"`
*   **출력:** `4`
*   **설명:**
    *   `s`의 끝에 "ding"을 추가하면 `s`는 "coachingding"이 됩니다.
    *   이제 `t`("coding")는 `s`(" **co**aching**ding** ")의 부분 수열이 됩니다.
    *   `s` 뒤에 3개의 문자만 추가해서는 절대 `t`를 부분 수열로 만들 수 없습니다.

**예제 2:**

*   **입력:** `s = "abcde"`, `t = "a"`
*   **출력:** `0`
*   **설명:**
    *   `t`는 이미 `s`의 부분 수열입니다 ("**a**bcde").

**예제 3:**

*   **입력:** `s = "z"`, `t = "abcde"`
*   **출력:** `5`
*   **설명:**
    *   `s`의 끝에 "abcde"를 추가하면 `s`는 "zabcde"가 됩니다.
    *   이제 `t`는 `s`의 부분 수열이 됩니다 ("z**abcde**").
    *   `s` 뒤에 4개의 문자만 추가해서는 절대 `t`를 부분 수열로 만들 수 없습니다.

---

**제약 조건:**

*   $1 \le s.length, t.length \le 10^5$
*   `s`와 `t`는 소문자 영문자로만 구성됩니다.
*/
