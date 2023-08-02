#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))
using namespace std;

int arr[9][9];

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t i;
    size_t j;
    int average;
    int sum;
    int result;
    int min;
    int temp;

    for (i = 0; i < 9; i++) {
        sum = 0;
        for (j = 0; j < ARRAY_LENGTH; j++) {
            cin >> arr[i][j];
            sum = sum + arr[i][j];
        }

        average = (sum / 9.0) + 0.5;
        printf("%d ", average);
        min = 2147000000;

        for (j = 0; j < 9; j++) {
            temp = abs(arr[i][j] - average);
            if (temp < min) {
                min = temp;
                result = arr[i][j];
            }
            else if (temp == min) {
                if (arr[i][j] > average) {
                    result = arr[i][j];
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
