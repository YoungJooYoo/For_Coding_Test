#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
int main(void)
{
    size_t n;
    size_t i;
    size_t digits = 9; /* 1의자리 9개, 추후 100 , 100 자리수에도 쓰임 9, 90, 900등으로 변화 */
    size_t count = 1; /* 1자리 숫자 1 * 9 = 9개, 2자리 숫자 2 * 90 = 180개 용도 */
    size_t sum = 0; /* 1의 자리 숫자 2의자리 숫자 3의자리 숫자등의 갯수를 누적하는 변수 */
    size_t result = 0;

    cin >> n;

    while (sum + digits < n) {
        result = result + (count * digits);
        sum = sum + digits;
        count++; /* 이제 두자리수다, 세자리 수다 나타낸다. */
        digits = digits * 10;/* 이것으로 자리수별 숫자 카운팅해준다. */
    }

    result = result + ((n - sum) * count);

    cout << result << endl;
   
	return 0;
}
/* 

문제 접근법

자연수 기준 

1자리 숫지 1 ~ 9 숫자 9개
2자리 숫자 10 ~99  90개
3자리 숫자 100 ~ 999 900개

패턴이 보인다.

1의자리는 9개
2의자리는 180개의 숫자


예를 들어 1 ~ 256은
1의자리 + 2의 자리 + 3의자리 숫자의 갯수의 합이다.
 
 1의 자리는 9개를 이미 알고
 2자리 숫자는 90개 구한 것을 아니

 100~256까지 3자리가 얼마나 쓰였는지 알면 된다

 즉 256 - 90 - 9 = 157개의 3자리 수가 사용 되었다.
 여기에 157 * 3 = 3자리 숫자의 갯수

*/
