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

int DFS(int x, int y)
{
    if (dp[x][y] > 0) return dp[x][y];
    if (x == 0 && y == 0) {
        return arr[0][0];
    }
    
    if (y == 0) return dp[x][y] = DFS(x - 1, y) + arr[x][y];
    else if (x == 0) return dp[x][y] = DFS(x, y - 1) + arr[x][y];
    else return dp[x][y] =  min(DFS(x - 1, y), DFS(x, y - 1)) + arr[x][y];
}

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

    cout << DFS(n - 1, n - 1) << endl;

    return 0;
}
