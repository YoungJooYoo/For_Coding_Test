#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;

size_t map[100][100];
size_t row[4] = {-1, 0, 1, 0};  // 상하좌우용 배열
size_t col[4] = { 0, 1, 0, -1}; // 상하좌우용 배열

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t n;
    size_t i;
    size_t j;
    size_t k;
    size_t count_peaks = 0;
    bool flag;

    cin >> n;
    // 테두리를 0으로 남기기 위해 1부터 시작
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            flag = false;
            for (k = 0; k < 4; k++) {
                if (map[i][j] <= map[i + row[k]][j + col[k]]) {
                    flag = true;  // 봉우리가 주변보다 부조건 커야하는데 조건에 맞지 않으면 false하고 더 볼 필요없이 탐색 종료
                    break;
                }
            }
            if (flag == false) {
                count_peaks++;
            }
        }
    }
     
    cout << count_peaks << endl;
    return 0;
}

