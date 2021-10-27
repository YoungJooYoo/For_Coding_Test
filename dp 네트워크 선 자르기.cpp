#pragma warning(disable:4996)
#include <iostream>
using namespace std;

size_t memoization[50];

int main(void) 
{
    // freopen("input.txt", "rt", stdin);
    size_t n;
    memoization[1] = 1;
    memoization[2] = 2;

    cin >> n;

    for (size_t i = 3; i <= n; i++)
    {
        memoization[i] = memoization[i - 1] + memoization[i - 2];
    }
    
    cout << memoization[n] << endl;

    return 0;
} 
