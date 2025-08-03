class Solution
{
public:
    string complexNumberMultiply(const string& num1, const string& num2) const
    {
        const pair<int, int> n1 = parseComplex(num1);
        const pair<int, int> n2 = parseComplex(num2);
        const int real = n1.first * n2.first - n1.second * n2.second;
        const int imag = n1.first * n2.second + n1.second * n2.first;

        assert(MIN_VAL <= n1.first && n1.first <= MAX_VAL);
        assert(MIN_VAL <= n1.second && n1.second <= MAX_VAL);
        assert(MIN_VAL <= n2.first && n2.first <= MAX_VAL);
        assert(MIN_VAL <= n2.second && n2.second <= MAX_VAL);

        return to_string(real) + "+" + to_string(imag) + "i";
    }

private:
    pair<int, int> parseComplex(const string& s) const
    {
        const size_t plusPos = s.find('+');
        const int real = stoi(s.substr(0, plusPos));
        const int imag = stoi(s.substr(plusPos + 1, s.length() - plusPos - 2));
        
        assert(plusPos != string::npos && s.back() == 'i');
        return make_pair(real, imag);
    }

    enum
    {
        MIN_VAL = -100,
        MAX_VAL = 100
    };
};

// https://leetcode.com/problems/complex-number-multiplication/description/

/*
네! 아래는 **Leetcode 537. Complex Number Multiplication** 문제의 **한국어 번역**입니다.

---

## 537. 복소수 곱셈

**난이도: 중**

---

### 문제 설명

복소수는 `"실수부+허수부i"` 형태의 문자열로 표현할 수 있습니다.

* **실수부(real)**: 정수, 범위는 \[-100, 100]
* **허수부(imaginary)**: 정수, 범위는 \[-100, 100]
* **i² = -1**임을 참고하세요.

두 복소수 `num1`, `num2`가 문자열로 주어질 때,
**두 복소수의 곱을 복소수 형태의 문자열로 반환하세요.**

---

### 예시

#### 예시 1

**입력:**
num1 = "1+1i", num2 = "1+1i"

**출력:**
"0+2i"

**설명:**
(1 + i) × (1 + i) = 1 + i² + 2i = 1 - 1 + 2i = 0 + 2i

---

#### 예시 2

**입력:**
num1 = "1+-1i", num2 = "1+-1i"

**출력:**
"0+-2i"

**설명:**
(1 - i) × (1 - i) = 1 + i² - 2i = 1 - 1 - 2i = 0 + -2i

---

### 제약사항

* num1, num2는 **올바른 복소수 문자열**입니다.

---

추가 설명, 코드, 해설 등이 필요하시면 언제든 말씀해 주세요!

*/
