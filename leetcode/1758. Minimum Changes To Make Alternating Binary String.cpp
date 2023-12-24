class Solution {
public:
    int minOperations(string& s) 
    {
        const int LEN = s.size();
        int count = 0;

        for (size_t i = 0; i < LEN; ++i) {
            if (s[i] - '0' != i % 2) ++count;
        }

        return min(count, LEN - count);
    }
};
/*
풀이 :

인덱스의 순서가 [0,1,2,3..]임을  알 수 있습니다.
2로 나누어 그 모듈을 얻으면 [0,1,0,1,0..]이 되는데,
이는 우리가 원하는 번갈아가는 이진 수열입니다.

그래서 문자열을 반복하면서,
문자열의 characters[i]가 i % 2와 같은지 확인합니다.
여기서 s[i]는 문자이며, s[i] - '0'을 통해 정수로 만듭니다.

우리는 차이의 개수를 누적하며,
이는 01 문자열로 만들기 위한 작업의 횟수입니다.

res를 찾는 데에도 같은 작업을 수행하여
10 문자열을 만들기 위한 작업의 횟수를 찾을 수 있습니다.
하지만 우리는 이를 찾을 필요가 없습니다.
왜냐하면 이는 s.length - res와 같기 때문입니다.

count 01로 시작하느 경우
lEN - Count  10으로 시작하는 경우

*/

// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2023-12-24
