#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

size_t map[51][51];

int main(int argc, const char * argv[]) {
    //freopen("test.txt", "rt", stdin);
    size_t n, m;
    size_t row, column, value;
    
    cin >> n >> m;
    
    for (size_t i = 1; i <= m; ++i) {
        cin >> row >> column >> value;
        map[row][column] = value;
    }
  
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
