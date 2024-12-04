#define NULL_CHAR ('\0')

class Solution 
{
public:
    bool canMakeSubsequence(const string& str1, const string& str2) const
    {
        size_t i = 0;
        size_t j = 0;

        while (str1[i] != NULL_CHAR && str2[j] != NULL_CHAR)
        {
            const char currChar = str1[i];
            const char nextChar = (currChar == 'z') ? 'a' : currChar + 1;
            if (currChar == str2[j] || nextChar == str2[j])
            {
                ++j;
            }
            ++i;
        }

        return (j == str2.size()) ? true : false;
    }
};

// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04

/*
**2825. 문자열을 순환 증가를 사용하여 부분 수열로 만들기**  
난이도: 중간  

**문제 설명**  
두 개의 0-인덱스 문자열 `str1`과 `str2`가 주어집니다.

하나의 연산에서, `str1`의 인덱스 집합을 선택하고 각 인덱스 `i`에 대해 `str1[i]`를 다음 문자로 순환적으로 증가시킵니다. 즉, 'a'는 'b'가 되고, 'b'는 'c'가 되며, ... 'z'는 'a'가 됩니다.

`str2`가 `str1`의 부분 수열이 되도록 위 연산을 한 번 이하로 수행하여 만들 수 있는지 확인하고, 가능하면 `true`, 불가능하면 `false`를 반환하세요.

참고: 문자열의 부분 수열은 원래 문자열에서 일부(없을 수도 있는) 문자를 삭제하여 나머지 문자들의 상대적 순서를 유지하면서 형성된 새로운 문자열입니다.

**예제**  
- 예제 1:
  - 입력: `str1 = "abc"`, `str2 = "ad"`
  - 출력: `true`
  - 설명: `str1`에서 인덱스 2를 선택하여 `str1[2]`를 'd'로 증가시킵니다. 따라서 `str1`은 `"abd"`가 되고, `str2`는 부분 수열이 됩니다. 따라서 `true`를 반환합니다.

- 예제 2:
  - 입력: `str1 = "zc"`, `str2 = "ad"`
  - 출력: `true`
  - 설명: `str1`의 인덱스 0과 1을 선택하여 `str1[0]`을 'a'로, `str1[1]`을 'd'로 증가시킵니다. 따라서 `str1`은 `"ad"`가 되고, `str2`는 부분 수열이 됩니다. 따라서 `true`를 반환합니다.

- 예제 3:
  - 입력: `str1 = "ab"`, `str2 = "d"`
  - 출력: `false`
  - 설명: 이 예제에서는 `str1`을 한 번 이하의 연산으로 `str2`의 부분 수열로 만드는 것이 불가능하므로 `false`를 반환합니다.

**제약 사항**  
- `1 <= str1.length <= 10^5`
- `1 <= str2.length <= 10^5`
- `str1`과 `str2`는 오직 소문자 영어 문자로만 구성됩니다.
*/
