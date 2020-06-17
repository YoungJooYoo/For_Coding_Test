#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;


size_t cache[10];

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t cache_size;
    size_t n;
    size_t i;
    size_t j;
    size_t task_num;
    int pos = -1; /* cache hit시 배열의 index를 저장할 변수 */

    cin >> cache_size;
    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> task_num;
        pos = -1; /* 캐시 hit배열의 인덱스 초기화 */

        /* 캐시가 hit 일때 */
        for (j = 0; j < cache_size; j++) {
            if (cache[j] == task_num) {
                pos = j; /* 히트가 난 위치를 저장 */
            }
        }
        
        /* 캐시가 miss 일때, 삽입정렬로 밀어내서 저장한다 */
        if (pos == -1) {
            for (j = cache_size - 1; j >= 1; j--) {
                cache[j] = cache[j - 1];
            }
        }
        else { /* 캐시가 hit일때 아까 저장해둔 pos를 사용 */
            for (j = pos; j >= 1; j--) {
                cache[j] = cache[j - 1];
            }
        }
        cache[j] = task_num; /* j = 0 일때 입력 받은 task를 넣게된다. or cache[0] == task_num 가능 */
    }

    for (i = 0; i < cache_size; i++) {
        cout << cache[i] << " ";
    }

    return 0;
}
