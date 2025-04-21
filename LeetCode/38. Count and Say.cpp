class Solution 
{
public:
    string countAndSay(const int n) const 
    {
        assert(MIN_N <= n && n <= MAX_N);

        string result = "1";

        for (int i = 2; i <= n; ++i) 
        {
            result = nextCountAndSayHelper(result);
        }

        return result;
    }

private:
    string nextCountAndSayHelper(const string& s) const 
    {
        string output;
        const int len = s.size();
        int count = 1;

        for (int i = 1; i <= len; ++i) 
        {
            if (s[i] == s[i - 1]) 
            {
                ++count;
            } 
            else 
            {
                output += to_string(count); // run 끝: 개수 + 문자              
                output.push_back(s[i - 1]);
                count = 1;
            }
        }

        return output;
    }

    enum 
    {
        MIN_N = 1,
        MAX_N = 30
    };
};


// https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-21

/*
**38. 읽기-쓰기 수열 (Count and Say)**

**난이도:** 중간

**문제 설명:**  
읽기-쓰기 수열(count-and-say sequence)은 아래와 같이 재귀적으로 정의되는 숫자 문자열(sequence)입니다.

1. `countAndSay(1) = "1"`  
2. `countAndSay(n)`은 `countAndSay(n‑1)`을 **런렝스 인코딩(Run‑Length Encoding, RLE)** 한 결과입니다.

**런렝스 인코딩(RLE)** 은 연속해서 같은 문자가 2개 이상 반복될 때,  
- 반복되는 문자 하나와  
- 그 반복 횟수(연속된 길이)를  
문자열로 이어 붙여 압축하는 기법입니다.  

예를 들어, `"3322251"`을 RLE 하면:  
- `"33"` → `"23"`  (문자 `'3'`가 2번)  
- `"222"` → `"32"` (문자 `'2'`가 3번)  
- `"5"` → `"15"`  (문자 `'5'`가 1번)  
- `"1"` → `"11"`  (문자 `'1'`가 1번)  
을 차례로 합쳐 `"23321511"`이 됩니다.

주어진 양의 정수 `n`에 대해, `countAndSay(n)`을 반환하세요.

---

**예제 1:**

- **입력:** `n = 4`  
- **출력:** `"1211"`  
- **설명:**  
  1. `countAndSay(1) = "1"`  
  2. `countAndSay(2)` = RLE("1") = `"11"`  
  3. `countAndSay(3)` = RLE("11") = `"21"`  
  4. `countAndSay(4)` = RLE("21") = `"1211"`

---

**예제 2:**

- **입력:** `n = 1`  
- **출력:** `"1"`  
- **설명:**  
  기본 사례(base case)입니다.

---

**제약 조건:**

- `1 <= n <= 30`
*/
