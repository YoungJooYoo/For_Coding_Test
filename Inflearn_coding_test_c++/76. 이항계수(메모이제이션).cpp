#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

int memoization[5000][5000];

int recursive(int n, int r)
{
    if (memoization[n][r] != 0)
    {
        return memoization[n][r];
    }
    if (n == r || r == 0) 
    {
        return 1;
    }
    // 5c3 => 4c2 + 4c3 이런식으로 재귀
    return memoization[n][r] = recursive(n - 1, r - 1) + recursive(n - 1, r);
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);

    size_t n, r;

    cin >> n >> r;
    cout << recursive(n, r) << endl;
    return 0;
} 
