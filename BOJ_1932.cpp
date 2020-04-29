/* 1932 정수 삼각형 */
#include <iostream>
#include <algorithm>
#define ARR_SIZE (502)

using namespace std;

size_t num[ARR_SIZE][ARR_SIZE];
size_t dp[ARR_SIZE][ARR_SIZE];

int main(void)
{
    size_t n;
    size_t i;
    size_t j;
    size_t max_sum = 0;

    cin >> n;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }

    /* dp에 저장된 더하기 누적값을 최대값만 찾아서 계속 더한다. */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            dp[i][j] = num[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    for (i = 0; i <= n ; i++) {
        max_sum = max(max_sum, dp[n][i]);
    }

    cout << max_sum << endl;

    return 0;
}
