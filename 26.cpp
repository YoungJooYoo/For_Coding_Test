#include <iostream>
#include <stdio.h>

using namespace std;

size_t runners[10000 + 1];

int main(void)
{
    size_t i;
    size_t j;
    size_t n;
    size_t rank_count = 0;

    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> runners[i];
    }

    cout << "1 "; /* 첫번째 원소는 일단 1등 그룹 */

    /* 2등부터 자기 등수를 생각한다. */
    for (i = 2; i <= n; i++) { /* i를 기준으로 하고, */
        for (j = i -1; j >= 1 ; j--) { /* i - 1은 i기준보다 앞에 있는 값부터 비교, 1번째 원소가지*/
            if (runners[j] >= runners[i]) {
                rank_count++;
            }
        }
        cout << rank_count + 1 << " ";
        rank_count = 0; /* 원소당 등수를 카운트하고 다시 초기화 */
    }

    return 0;
}
