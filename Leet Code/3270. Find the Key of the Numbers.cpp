class Solution {
public:
    int generateKey(const int num1, const int num2, const int num3) 
    {
        const string NUMBER1 = toFourDigitString(num1);
        const string NUMBER2 = toFourDigitString(num2);
        const string NUMBER3 = toFourDigitString(num3);

        string result;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const int NUMBER = min((NUMBER1[i] - '0'), min((NUMBER2[i] - '0'), (NUMBER3[i]) - '0'));
            result += (NUMBER + '0');  // 변경: int를 char로 변환하여 추가
        }

        assert(result.size() > 0);
        return stoi(result);
    }

private:
    const string toFourDigitString(const int num) const
    {
        string number = to_string(num);
        
        while (number.size() < LENGTH)
        {
            number = "0" + number;
        }

        assert(number.size() == LENGTH);
        return number;
    }

private:
    enum { LENGTH = 4 };
};

// https://leetcode.com/problems/find-the-key-of-the-numbers/description/

/*
### 문제 설명:

세 개의 양의 정수 `num1`, `num2`, `num3`이 주어집니다.

이 세 숫자의 "키"(key)는 다음과 같은 4자리 숫자로 정의됩니다:

1. 처음에, 각 숫자가 4자리가 되도록 앞에 0을 채워줍니다.
2. `num1`, `num2`, `num3`의 각각의 자리에서 가장 작은 숫자를 선택하여 키를 만듭니다.
3. 생성된 키에서 앞의 0을 제거하고 반환합니다.

### 예제:

#### 예제 1:
- 입력: `num1 = 1`, `num2 = 10`, `num3 = 1000`
- 출력: `0`
- 설명:
  - `num1`은 `"0001"`, `num2`는 `"0010"`, `num3`는 `"1000"`이 됩니다.
  - 각 자리의 최소값은 `"0000"`이므로 결과는 `0`입니다.

#### 예제 2:
- 입력: `num1 = 987`, `num2 = 879`, `num3 = 798`
- 출력: `777`
- 설명:
  - 각 숫자를 4자리로 만든 결과는 `"0987"`, `"0879"`, `"0798"`입니다.
  - 각 자리의 최소값은 `"0777"`이므로 결과는 `777`입니다.

#### 예제 3:
- 입력: `num1 = 1`, `num2 = 2`, `num3 = 3`
- 출력: `1`
- 설명:
  - 각 숫자를 4자리로 만든 결과는 `"0001"`, `"0002"`, `"0003"`입니다.
  - 각 자리의 최소값은 `"0001"`이므로 결과는 `1`입니다.

### 제한사항:

- `1 <= num1, num2, num3 <= 9999`

*/
