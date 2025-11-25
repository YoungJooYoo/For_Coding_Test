class Solution
{
public:
    int minimumFlips(int n) const
    {
        assert(MIN_N <= n && n <= MAX_N);

        string bits;
        bits.reserve(INT_BIT_LENGTH); // int 범위에서 최대 32비트

        while (n > 0)
        {
            const int bit = n & 1;
            bits.push_back(static_cast<char>('0' + bit));
            n >>= 1;
        }

        const size_t LEN = bits.size();
        int flipCount = 0;

        for (size_t i = 0; i < LEN; ++i)
        {
            const char originalBit = bits[LEN - 1 - i];
            if (bits[i] != originalBit)
            {
                ++flipCount;
            }
        }

        assert(flipCount >= 0);
        return flipCount;
    }

private:
    enum
    {
        MIN_N = 1,
        MAX_N = 1000000000,
        INT_BIT_LENGTH = 32,
    };
};

// https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/

/*
3750. 이진 문자열을 뒤집기 위한 최소 비트 플립 횟수
힌트
양의 정수 n이 주어집니다.

s는 n의 이진 표현에서 선행하는 0을 제외한 문자열입니다.

이진 문자열 s의 **뒤집힌 형태(reverse)**는 s의 문자들을 반대 순서로 작성하여 얻습니다.

당신은 s의 어떤 비트라도 플립(flip)할 수 있습니다 (0을 1로 또는 1을 0으로 변경). 각 플립은 정확히 하나의 비트에 영향을 미칩니다.

s를 원래 형태를 뒤집은 것과 같게 만들기 위해 필요한 최소 플립 횟수를 반환하세요.

예시 1:

입력: n = 7
출력: 0
설명:
7의 이진 표현은 "111"입니다. 이를 뒤집어도 "111"이 되므로 같습니다. 따라서 플립이 필요하지 않습니다.

예시 2:

입력: n = 10
출력: 4
설명:
10의 이진 표현은 "1010"입니다. 이를 뒤집으면 "0101"입니다. 두 문자열을 같게 만들려면 네 개의 비트를 모두 플립해야 합니다. 따라서 필요한 최소 플립 횟수는 4입니다.

제약 조건:

1 <= n <= 10^9
*/
