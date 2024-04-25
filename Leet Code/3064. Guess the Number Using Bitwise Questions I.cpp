/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() 
    {
        int ans = 0;
        
        for (int i = 0; i < 31; ++i) {
            if (commonSetBits(1 << i)) {
                ans |= 1 << i;
            }
        }

        return ans;
    }
};
/*

이 문제에서는 주어진 숫자 n을 찾아야 합니다. 주어진 API int commonSetBits(int num)은 n과 num의 이진 표현에서 해당 위치에서 둘 다 1인 비트의 수를 반환합니다. 즉, n과 num의 이진 표현에서의 & 연산의 결과의 비트 수를 반환합니다.

예를 들어, n = 31인 경우를 생각해보면, 31의 이진 표현은 11111입니다. 따라서 commonSetBits 함수에 31을 넘겨주면, num이 어떤 값이든 상관없이 31과 num의 & 연산 결과에서 1인 비트의 개수를 반환합니다. 그리고 이 값이 항상 5입니다. 따라서 commonSetBits 함수를 사용하여 31을 찾을 수 있습니다.

다음으로, n = 33인 경우를 생각해보면, 33의 이진 표현은 100001입니다. 마찬가지로 commonSetBits 함수를 사용하여 33을 찾을 수 있습니다.

즉, 이 문제에서는 주어진 API를 사용하여 숫자 n을 찾아야 합니다.

혹시 위 문제의 목표를 이해하셨나요?
*/
