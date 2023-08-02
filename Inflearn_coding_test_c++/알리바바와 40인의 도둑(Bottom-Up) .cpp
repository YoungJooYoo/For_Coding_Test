#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

# define ARR_LEN (21)
int arr[ARR_LEN][ARR_LEN];
int dp[ARR_LEN][ARR_LEN];

int main(void)
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);
    
    size_t n;
 
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];

    for (size_t i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + arr[0][i];
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }

    for (size_t i = 1; i < n; i++) {
        for (size_t j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }
  
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
