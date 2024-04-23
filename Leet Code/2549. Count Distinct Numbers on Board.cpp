class Solution {
public:
    int distinctIntegers(int n) 
    {
        if (n == 1) {
            return 1;
        }

        return n - 1;
    }
};

/*


**2549. 보드에 있는 고유한 숫자 세기**

양의 정수 n이 주어지며, 이는 초기에 보드에 배치됩니다. 매일, 10^9일 동안 다음 절차를 수행합니다.

보드에 있는 각 숫자 x에 대해, x % i == 1을 만족하는 모든 숫자 1 <= i <= n을 찾습니다.
그런 다음 해당 숫자를 보드에 배치합니다.
10^9일이 지난 후 보드에 존재하는 고유한 정수의 수를 반환합니다.

주의 사항:

한 번 숫자가 보드에 배치되면 끝날 때까지 보드에 남습니다.
%는 나머지 연산을 나타냅니다. 예를 들어, 14 % 3은 2입니다.
**Constraints:**

1 <= n <= 100

예시를 통해 문제를 이해해보겠습니다.

예시를 통해 문제를 이해해보겠습니다.

**예시 1:**

입력: n = 5

출력: 4

설명: 초기에 5가 보드에 있습니다.
다음 날, 5 % 2 == 1 및 5 % 4 == 1을 만족하는 숫자 2와 4가 추가됩니다.
그 다음 날, 4 % 3 == 1을 만족하는 숫자 3이 보드에 추가됩니다.
10^9일이 지난 후, 보드에 있는 고유한 숫자는 2, 3, 4, 5입니다.

**예시 2:**

입력: n = 3

출력: 2

설명: 3 % 2 == 1이므로 다음 날, 2가 보드에 추가됩니다.
10^9일이 지난 후, 보드에 있는 유일한 두 개의 고유한 숫자는 2와 3입니다.


*/

// https://leetcode.com/problems/count-distinct-numbers-on-board/
