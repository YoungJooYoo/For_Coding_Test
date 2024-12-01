class Solution {
public:
    int smallestNumber(const int n) 
    {
        return convertBinaryToInt(convertIntToBinaryOnlyOne(n));
    }

private:
    string convertIntToBinaryOnlyOne(int n)
    {
        string result;
        
        while (n != 0)
        {
            result.push_back('1');
            n /= 2;
        }

        return result;
    }

    int convertBinaryToInt(const string& binary)
    {
        const size_t LENGTH = binary.size();
        int result = 0;
        
        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (binary[i] == '1')
            {
                result += (1 << (LENGTH - 1 - i));
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/smallest-number-with-all-set-bits/description/

/*
**3370. 모든 비트가 설정된 가장 작은 수**  
난이도: 쉬움  

---

양의 정수 `n`이 주어졌습니다.

`n`보다 크거나 같은 수 중에서 이진수 표현이 모든 비트가 1로 설정된 가장 작은 수 `x`를 반환하세요.

설정된 비트(set bit)는 이진수 표현에서 값이 1인 비트를 의미합니다.

---

### 예제 1:

입력: 
```
n = 5
```
출력: 
```
7
```
설명:  
- 7의 이진 표현은 `"111"`입니다.

### 예제 2:

입력: 
```
n = 10
```
출력: 
```
15
```
설명:  
- 15의 이진 표현은 `"1111"`입니다.

### 예제 3:

입력: 
```
n = 3
```
출력: 
```
3
```
설명:  
- 3의 이진 표현은 `"11"`입니다.

---

### 제약 사항:

- `1 <= n <= 1000`
*/
