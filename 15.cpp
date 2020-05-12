#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
    size_t n;
    size_t i;
    size_t j;
    size_t count = 0;
    size_t flag;

    cin >> n;

    /* i = 2 부터, 자연수 시작 범위가 2이므로 */
    for (i = 2; i <= n; i++) {
        flag = 1;
        for (j = 2; j* j <= i; j++) {
            if (i % j == 0) { /* 소수검사 범위가 1과 자기 자신의 범위는 제외했으므로 약수가 발견되면 소수가 아님 */
                flag = 0;
                break;
            }
        }
        if (flag == 1) { 
            count++;
        }
    }
   
    cout << count << endl;

	return 0;
}
