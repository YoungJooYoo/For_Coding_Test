#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;

size_t prince[1000 + 1]; /* 인덱스를 1부터 사용하기 위해 1 ~ n + 1 범위로 선언 */

void print_solution(size_t n, size_t prince[]);

int main(void)
{
    size_t n;
    size_t k;
    size_t pos = 0;
    size_t count = 0;
    size_t break_point = 0; /* n - 1개가 되면 멈추게 하는 변수 */
    
    cin >> n >> k;
    
    /* 왕자가 1명 남았을때 탈출 */
    while(true) {
        pos++;
        /* pos가 n을 초과하면 다시 1로 */
        if (pos > n) {
            pos = 1;
        }
        if (prince[pos] == 0) {
            count++;
            if (count == k) {
                prince[pos] = 1;
                count = 0;
                break_point++;
            }
        }
        /* 왕자가 1명 남을때 탈출 */
        if (break_point == n - 1) {
            break;
        }
        
    }
    
    print_solution(n, prince);
    return 0;
}

void print_solution(size_t n, size_t prince[])
{
    size_t i;
    /* 유일하게 남은 prince[i] == 0인 인덱스를 출력 */
    for (i = 1; i <= n; i++) {
        if (prince[i] == 0) {
            cout << i << endl;
            break;
        }
    }
}
