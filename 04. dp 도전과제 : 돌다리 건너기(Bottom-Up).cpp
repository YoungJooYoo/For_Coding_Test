#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

size_t memoization[50000];

// 돌다리를 건너는 것, 돌다리 도착이 아니라 돌다리를 건너야 하므로. 돌다리 도착 + 1이 답인 문제이다.
// 돌다리가 7개라면 도착은 +1개 이므로 8개인 경우 답을 구한다.

int recursive(int n)
{
    if (memoization[n] > 0)
    {
        return memoization[n];
    }

    if (n == 1 || n == 2)
    {
        return n;
    }
    
    memoization[n] = recursive(n - 1) + recursive(n - 2);
    return memoization[n];
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);
    size_t n;
 
    cin >> n;
    cout << recursive(n + 1) << endl;

    return 0;
} 
