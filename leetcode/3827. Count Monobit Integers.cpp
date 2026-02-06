class Solution 
{
public:
    int countMonobit(const int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        // n = 0 → "0" 하나 존재
        if (n == 0)
        {
            return 1;
        }

        int result = 1; // 0 포함

        for (int i = 1; i <= n; ++i)
        {
            const string strNumber = getStringBinaryNum(i);
            const int length = static_cast<int>(strNumber.length());
            const int oneCount = getOneCount(strNumber);
            if (length == oneCount)
            {
                ++result;
            }
        }

        assert(result >= 0);
        return result;
    }

private:
    string getStringBinaryNum(int dec) const
    {
        int bin = 0;
        long long powerOfTen = 1;

        while (dec > 0)
        {
            bin += (dec % 2) * powerOfTen;
            powerOfTen *= 10;
            dec /= 2;
        }

        return to_string(bin);
    }

    int getOneCount(const string& strNumber) const
    {
        int count = 0;

        for (const char ch : strNumber)
        {
            if (ch == '1')
            {
                ++count;
            }
        }

        return count;
    }

private:
    enum
    {
        MIN_N = 0,
        MAX_N = 1000
    };
};


/*

https://leetcode.com/problems/count-monobit-integers/description/

827. Monobit 정수 개수 세기 (Count Monobit Integers)

난이도: Easy
주제: (원문 유지)

정수 n이 주어진다.

정수의 이진수 표현에서 모든 비트가 동일하면, 해당 정수를 Monobit 정수라고 한다.

구간 [0, n] (양 끝 포함) 내에 존재하는 Monobit 정수의 개수를 반환하라.

예시 1

입력:

n = 1


출력:

2


설명:
구간 [0, 1]에 포함된 정수는 0과 1이며,
이들의 이진수 표현은 "0"과 "1"이다.
각각의 이진 표현은 모든 비트가 동일하므로, 답은 2이다.

예시 2

입력:

n = 4


출력:

3


설명:
구간 [0, 4]에 포함된 정수들의 이진수 표현은 다음과 같다:

0   -> 0
1   -> 1
2   -> 10
3   -> 11
4   -> 100


이 중 Monobit 조건을 만족하는 정수는 0, 1, 3 이므로
정답은 3이다.
*/
