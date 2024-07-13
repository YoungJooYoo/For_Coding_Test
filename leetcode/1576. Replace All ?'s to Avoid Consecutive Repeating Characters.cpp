class Solution 
{
public:
    string modifyString(string& s) 
    {
        const size_t LENGTH = s.length();

        for (size_t i = 0; i < LENGTH; ++i) 
        {
            if (s[i] == '?') 
            {
                for (char ch = 'a'; ch <= 'z'; ++ch) 
                {
                    if (!((i > 0 && s[i - 1] == ch) || (i < LENGTH - 1 && s[i + 1] == ch))) 
                    {
                        s[i] = ch;
                        break;; // 연속되는 반복 문자가 발생하지 않도록 함
                    }
                }
            }
        }

        return s;
    }
};

// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/

/*
### 1576. 연속되는 반복 문자를 피하기 위해 모든 '?'를 대체하라

**난이도: 쉬움**

#### 문제 설명

소문자 영어 문자와 '?' 문자만 포함된 문자열 `s`가 주어졌을 때, 모든 '?' 문자를 소문자 문자로 변환하여 최종 문자열이 연속되는 반복 문자를 포함하지 않도록 하세요. '?' 문자가 아닌 문자는 수정할 수 없습니다.

주어진 문자열에는 '?'를 제외한 연속되는 반복 문자가 없다는 것이 보장됩니다.

모든 변환이 완료된 후의 최종 문자열을 반환하세요. 가능한 해결책이 여러 개 있는 경우, 그 중 하나를 반환하세요. 주어진 제약 조건에서 항상 답이 존재함이 보장됩니다.

#### 예제

**예제 1**:

- 입력: `s = "?zs"`
- 출력: `"azs"`
- 설명: 이 문제에 대한 25가지 해결책이 있습니다. "azs"부터 "yzs"까지 모두 유효합니다. "z"만은 "zzs"에서 연속되는 반복 문자를 포함하므로 유효하지 않습니다.

**예제 2**:

- 입력: `s = "ubv?w"`
- 출력: `"ubvaw"`
- 설명: 이 문제에 대한 24가지 해결책이 있습니다. "v"와 "w"만은 "ubvvw"와 "ubvww"에서 연속되는 반복 문자를 포함하므로 유효하지 않습니다.

#### 제약 조건

- `1 <= s.length <= 100`
- `s`는 소문자 영어 문자와 '?'로 구성됩니다.
*/
