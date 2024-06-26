class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) 
    {
        int digit_sum = 0;
        int temp = x;

        while (temp != 0) {
            digit_sum += (temp % 10);
            temp /= 10;
        }

        if (x % digit_sum == 0) {
            return digit_sum;
        }

        return -1;
    }
};

/*
해쉬드 수(Harshad Number)는 그 숫자의 각 자리수의 합으로 나누어 떨어지는 정수를 말합니다. 주어진 정수 x가 해쉬드 수인 경우에는 x의 각 자리수의 합을 반환하고, 그렇지 않은 경우에는 -1을 반환해야 합니다.

예를 들어,

- 입력: x = 18
  - 출력: 9
  - 설명: x의 각 자리수의 합은 9입니다. 18은 9로 나누어 떨어지므로 해쉬드 수입니다. 따라서 답은 9입니다.

- 입력: x = 23
  - 출력: -1
  - 설명: x의 각 자리수의 합은 5입니다. 23은 5로 나누어 떨어지지 않으므로 해쉬드 수가 아닙니다. 따라서 답은 -1입니다.

주어진 조건은 다음과 같습니다:
- 1 <= x <= 100





해쉬드 수는 어떤 숫자를 그 숫자를 이루는 각 자리의 숫자들의 합으로 나눌 수 있는 숫자를 말해요. 예를 들어, 18은 1과 8을 더한 값인 9로 나누어 떨어지기 때문에 해쉬드 수입니다. 하지만 23은 그렇지 않죠. 이 문제에서는 주어진 숫자가 해쉬드 수인 경우에는 숫자를 이루는 각 자리의 합을 반환하고, 그렇지 않은 경우에는 -1을 반환해야 해요.

*/

// https://leetcode.com/problems/harshad-number/
