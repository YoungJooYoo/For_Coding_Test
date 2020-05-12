#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
    char a[100 + 1];
    char b[100 + 1];
    size_t check_a[60] = {0, }; /* 소문자 26개 + 대문자 26개 = 52개 */
    size_t check_b[60] = {0, };
    size_t i;

    cin >> a; 
    cin >> b;

    for (i = 0; a[i] != '\0'; i++){
        if (a[i] >= 'A' && a[i] <= 'Z') {
            check_a[a[i] - 65]++; /* 아스키 a = 65, 65를 빼면 배열 0부터 사용 가능*/
        }
        else {
            check_a[a[i] - 71]++; /* 소문인 경우, 52개배열 27번째 인덱스 부터 대문자로 사용하기 위해 70 뺀다.*/
        }
        if (b[i] >= 'A' && b[i] <= 'Z') {
            check_b[b[i] - 65]++; 
        }
        else {
            check_b[b[i] - 71]++;
        }
    }

    for (i = 0; i <= 51; i++) {
        if (check_a[i] != check_b[i]) {
            cout << "NO" << endl;
            return 0; // or exit(0);
        }
    }

    cout << "YES" << endl;
 
	return 0;
}
