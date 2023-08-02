#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))
using namespace std;

size_t array_a[11][11];
size_t array_b[11];

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t i;
    size_t j;
    size_t n;
    size_t sum = 0;

    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> array_b[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            array_a[j][i] = array_b[i];
        }
    }
    
    for (i = n; i >= 1; i--) {
        cin >> array_b[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (array_a[i][j] > array_b[i]) {
                array_a[i][j] = array_b[i];
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            sum = sum + array_a[i][j];
        }
    }
    
    cout << sum << endl;

    return 0;
}
