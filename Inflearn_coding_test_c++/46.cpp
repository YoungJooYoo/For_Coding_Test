#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;

int task[2000 + 1];

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t n;
    size_t k;
    size_t i;
    size_t blackout_time = 0;
    size_t total_task_size = 0;
    
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> task[i];
        total_task_size = total_task_size + task[i];
    }
    cin >> k;
    
    /* 모든 일의 크키가, k보다 작거나 같으면 더 이상 처리할 작업이 없다면 -1 */
    if (k >= total_task_size) {
        cout << "-1" << endl;
        return 0;
    }
    
    /* 정전이 일어나기 전까지 처리하기 */
    i = 0;
    while (true) {
        i++;
        /* i가 n을 넘어가면 다시 처음으로 순환한다. */
        if (i > n) {
            i = 1;
        }
        if (task[i] == 0) {
            continue;
        }
        /* 이 밑의 조건은 자동으로 task[i] != 0 일때로 성립이 된다. */
        task[i]--;
        blackout_time++;
        if (blackout_time == k) {
            break;
        }
    }
    
    /* 정전이 일어나고 다음에 처리할 일을 찾고 출력 */
    while (true) {
        i++;
        if (i > n) {
            i = 1;
        }
        if (task[i] != 0) {
            break;
        }
    }
    
    cout << i << endl;
    
    return 0;
}
