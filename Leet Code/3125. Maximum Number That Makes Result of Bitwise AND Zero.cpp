class Solution 
{
public:
    long long maxNumber(long long n) 
    {
        int bitCount = 0;
        long long temp = n;

        while (temp > 0)
        {
            ++bitCount;
            temp >>= 1;
        }

        const long long x = (1LL << (bitCount - 1)) - 1;
        
        return x;
    }
};

// https://leetcode.com/problems/maximum-number-that-makes-result-of-bitwise-and-zero/description/

/*

3125. 비트 단위 AND 결과를 0으로 만드는 최대 정수
중간 난이도

주제

기업

힌트

정수 n이 주어집니다. x <= n을 만족하고, 범위 [x, n]에 있는 모든 수의 비트 단위 AND 연산 결과가 0이 되도록 하는 최대 정수 x를 반환하세요.

예제 1:
makefile
코드 복사
입력: n = 7
출력: 3
설명:

[6, 7]의 비트 단위 AND 연산 결과는 6입니다.
[5, 6, 7]의 비트 단위 AND 연산 결과는 4입니다.
[4, 5, 6, 7]의 비트 단위 AND 연산 결과는 4입니다.
[3, 4, 5, 6, 7]의 비트 단위 AND 연산 결과는 0입니다.
따라서, x = 3이 조건을 만족하는 최대 정수입니다.

예제 2:
makefile
코드 복사
입력: n = 9
출력: 7
설명:

[7, 8, 9]의 비트 단위 AND 연산 결과는 0입니다.
따라서, x = 7이 조건을 만족하는 최대 정수입니다.

예제 3:
makefile
코드 복사
입력: n = 17
출력: 15
설명:

[15, 16, 17]의 비트 단위 AND 연산 결과는 0입니다.
따라서, x = 15이 조건을 만족하는 최대 정수입니다.

제약 사항:
1 <= n <= 10^15
*/
