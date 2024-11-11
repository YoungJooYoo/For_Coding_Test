class Solution 
{
public:
    int smallestNumber(int n, const int t) 
    {
        while (digitProduct(n) % t != 0)
        {
            ++n;
        }

        return n;
    }

private:
    int digitProduct(int num)
    {
        int product = 1;

        while (num != 0)
        {
            const int digit = num % 10;
            product *= digit;
            num /= 10;
        }

        return product;
    }
};


// https://leetcode.com/problems/smallest-divisible-digit-product-i/description/

/*


**3345. 가장 작은 배수 자릿수 곱 I**  
난이도: 쉬움

---

두 정수 `n`과 `t`가 주어집니다. 자릿수의 곱이 `t`로 나누어떨어지는 `n` 이상의 가장 작은 수를 반환하세요.

---

### 예제 1:

입력: 
```
n = 10, t = 2
```
출력: 
```
10
```
설명:
- `10`의 자릿수 곱은 `1 * 0 = 0`입니다. `0`은 `2`로 나누어떨어지므로 조건을 만족하는 `10` 이상의 가장 작은 수는 `10`입니다.

### 예제 2:

입력: 
```
n = 15, t = 3
```
출력: 
```
16
```
설명:
- `16`의 자릿수 곱은 `1 * 6 = 6`입니다. `6`은 `3`으로 나누어떨어지므로 조건을 만족하는 `15` 이상의 가장 작은 수는 `16`입니다.

---

### 제약 사항:

- `1 <= n <= 100`
- `1 <= t <= 10`

이 문제는 주어진 숫자 `n` 이상 중에서 자릿수의 곱이 특정 값 `t`로 나누어떨어지는 가장 작은 숫자를 찾는 문제입니다.

*/
