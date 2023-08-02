#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;

size_t inversion_sequence[100];
size_t original_sequence[100];

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t i;
    size_t j;
    size_t n;
    size_t pos;

    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> inversion_sequence[i];
    }
   
    /* 가장 큰 숫자부터 처리한다. 삽입정렬 이용 */
    for (i = n; i >= 1; i--) {
        pos = i;
        for (j = 1; j <= inversion_sequence[i]; j++) {
            original_sequence[pos] = original_sequence[pos + 1];
            pos++; /* 삽입 정렬로 수열을 당겨서 저장해야 한다. 따라서 post가 증가 */
        }
        original_sequence[pos] = i;
    }

    for (i = 1; i <= n; i++) {
        cout << original_sequence[i] << " ";
    }
      
    return 0;
}
