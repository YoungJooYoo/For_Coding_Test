class Solution 
{
public:
    bool isBalanced(const string& num)
    {
        const size_t LENGTH = num.size();
        int evenSum = 0;
        int oddSum = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (i % 2 != 0) oddSum += num[i] - '0';
            else evenSum += num[i] - '0';
        }

        return (evenSum == oddSum) ? true : false;
    }
};

/*
물론입니다. 아래는 해당 LeetCode 문제의 한국어 번역입니다:

---

**3340. 균형 잡힌 문자열 확인**  
난이도: 쉬움

---

숫자로만 이루어진 문자열 `num`이 주어집니다. 문자열이 "균형 잡혔다(balanced)"고 하려면, 짝수 인덱스의 자리 수들의 합과 홀수 인덱스의 자리 수들의 합이 같아야 합니다.

`num`이 균형 잡힌 문자열이라면 `true`를 반환하고, 그렇지 않으면 `false`를 반환하세요.

---

### 예제 1:

입력: 
```
num = "1234"
```
출력: 
```
false
```
설명:
- 짝수 인덱스 자리의 숫자 합은 `1 + 3 == 4`이고, 홀수 인덱스 자리의 숫자 합은 `2 + 4 == 6`입니다.
- `4`와 `6`이 같지 않으므로 `num`은 균형 잡힌 문자열이 아닙니다.

### 예제 2:

입력: 
```
num = "24123"
```
출력: 
```
true
```
설명:
- 짝수 인덱스 자리의 숫자 합은 `2 + 1 + 3 == 6`이고, 홀수 인덱스 자리의 숫자 합은 `4 + 2 == 6`입니다.
- 두 값이 같으므로 `num`은 균형 잡힌 문자열입니다.

---

### 제약 사항:

- `2 <= num.length <= 100`
- `num`은 숫자로만 이루어져 있습니다.
*/
