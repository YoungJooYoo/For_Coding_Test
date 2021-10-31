#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

size_t memoization[50000];

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
    cout << recursive(n) << endl;

    return 0;
} 
