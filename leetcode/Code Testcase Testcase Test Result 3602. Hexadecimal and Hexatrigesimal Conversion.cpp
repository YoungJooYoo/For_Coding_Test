class Solution
{
public:
    string concatHex36(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);
        return getHexadecimalString(n * n) + getHexatrigesimalString(n * n * n);
    }

private:
    string getHexadecimalString(const int num) const
    {
        assert(num > 0);
        int number = num;
        string hex_num;

        while (number != 0)
        {
            const int mod = number % HEXADECIMAL;
            if (mod < 10)
            {
                hex_num.push_back('0' + mod);
            }
            else
            {
                hex_num.push_back('A' + (mod - 10));
            }

            number /= HEXADECIMAL;
        }

        assert(hex_num.size() > 0);
        ranges::reverse(hex_num);
        return hex_num;
    }

    string getHexatrigesimalString(const int num) const
    {
        assert(num > 0);
        int number = num;
        string hex_num;

        while (number != 0)
        {
            const int mod = number % HEXATRIGESIMAL;
            if (mod < 10)
            {
                hex_num.push_back('0' + mod);
            }
            else
            {
                hex_num.push_back('A' + (mod - 10));
            }

            number /= HEXATRIGESIMAL;
        }

        assert(hex_num.size() > 0);
        ranges::reverse(hex_num);
        return hex_num;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000,
        HEXADECIMAL = 16,
        HEXATRIGESIMAL = 36
    };
};

// https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/description/

/*



---

### 3602. 16진수와 36진수 변환

난이도: 쉬움

---

#### 문제 설명

정수 n이 주어집니다.

n의 제곱(n²)을 16진수(헥사데시멀)로 표현한 문자열과,
n의 세제곱(n³)을 36진수(헥사트리지섬)로 표현한 문자열을
순서대로 이어 붙인 결과를 반환하세요.

---

#### 16진수 (Hexadecimal)란?

* 16진수는 0~~9의 숫자와 대문자 A~~F를 사용하여
* 0부터 15까지의 값을 표현하는 진법입니다.

---

#### 36진수 (Hexatrigesimal)란?

* 36진수는 0~~9의 숫자와 대문자 A~~Z를 사용하여
* 0부터 35까지의 값을 표현하는 진법입니다.

---

#### 예시 1

입력: n = 13

출력: "A91P1"

설명:

* n² = 13 \* 13 = 169 → 16진수로 변환하면 "A9" (10\*16 + 9 = 169)
* n³ = 13 \* 13 \* 13 = 2197 → 36진수로 변환하면 "1P1" (1*36² + 25*36 + 1 = 2197)
* 두 결과를 이어 붙이면 "A9" + "1P1" = "A91P1"

---

#### 예시 2

입력: n = 36

출력: "5101000"

설명:

* n² = 36 \* 36 = 1296 → 16진수로 변환하면 "510" (5*16² + 1*16 + 0 = 1296)
* n³ = 36 \* 36 \* 36 = 46656 → 36진수로 변환하면 "1000" (1*36³ + 0*36² + 0\*36 + 0 = 46656)
* 두 결과를 이어 붙이면 "510" + "1000" = "5101000"

---

#### 제한 조건

* 1 ≤ n ≤ 1000

---

#### 풀이 힌트

* 정수 x를 진법 b로 변환하는 함수 toBase(x, b)를 구현하세요.
* 숫자 0~~9와 알파벳 A~~Z를 사용해 변환하면 됩니다.
* 문제 설명대로 변환 과정을 시뮬레이션하세요.

---



*/
