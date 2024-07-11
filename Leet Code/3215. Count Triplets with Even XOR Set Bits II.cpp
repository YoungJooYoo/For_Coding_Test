#include <vector>
using namespace std;

class Solution {
public:
    long long tripletCount(const vector<int>& a, const vector<int>& b, const vector<int>& c) 
    {
        long long result = 0;
        vector<long long> count_a(2, 0);
        vector<long long> count_b(2, 0);
        vector<long long> count_c(2, 0);

        for (const int& n : a) 
        {
            count_a[__builtin_popcount(n) % 2]++;
        }
        for (const int& n : b) 
        {
            count_b[__builtin_popcount(n) % 2]++;
        }
        for (const int& n : c) 
        {
            count_c[__builtin_popcount(n) % 2]++;
        }

        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                for (int k = 0; k < 2; k++) 
                {
                    if ((i + j + k) % 2 == 0) 
                    {
                        result += count_a[i] * count_b[j] * count_c[k];
                    }
                }
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/count-triplets-with-even-xor-set-bits-ii/description/

/*

문제 번역
3215. 짝수 XOR 세트 비트를 가진 삼중항 세기 II

난이도: 중간

문제 설명
세 개의 정수 배열 a, b, c가 주어질 때, 각 삼중항 (a[i], b[j], c[k])의 비트 XOR 연산의 결과가 짝수 개의 세트 비트를 가지는 삼중항의 수를 반환하세요.

예제
예제 1:

입력: a = [1], b = [2], c = [3]
출력: 1
설명:
유일한 삼중항은 (a[0], b[0], c[0])이고 그들의 XOR는 1 XOR 2 XOR 3 = 0(2진수)입니다.
예제 2:

입력: a = [1,1], b = [2,3], c = [1,5]
출력: 4
설명:
다음 네 가지 삼중항을 고려해봅시다:
(a[0], b[1], c[0]): 1 XOR 3 XOR 1 = 3(2진수 011)
(a[1], b[1], c[0]): 1 XOR 3 XOR 1 = 3(2진수 011)
(a[0], b[0], c[1]): 1 XOR 2 XOR 5 = 6(2진수 110)
(a[1], b[0], c[1]): 1 XOR 2 XOR 5 = 6(2진수 110)
제약 조건
1 <= a.length, b.length, c.length <= 105
0 <= a[i], b[i], c[i] <= 109
*/
