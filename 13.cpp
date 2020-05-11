#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
int main(void)
{
    char number[9 + 1] = {0, }; /* 0 ~ 9 자연수 나온 횟수를 카운팅할 배열 */
    char n[100 + 1];
    size_t i;
    size_t max = 0;
    size_t result = 0;

    cin >> n;

    for (i = 0; n[i] != '\0'; i++) {
        number[n[i] - 48]++; /* 문자형 숫자 - 48 = 정수가 된다. 즉 숫자배열에 나온 횟수를 체크 */
    }

    for (i = 0; i < 10; i++) {
        if (number[i] >= max) {
            max = number[i];
            result = i;
        }
    }

    cout << result << endl;

	return 0;
}