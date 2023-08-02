#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

size_t ugly_number[1501];


int main(void) 

{
    //freopen("input.txt", "rt", stdin);

    size_t i;
    size_t n;
    size_t num_2 = 1;
    size_t num_3 = 1;
    size_t num_5 = 1;
    size_t min_value = 2147000000;
    ugly_number[1] = 1;

    cin >> n;

    for (i = 2; i <= n; i++)
    {
        if (ugly_number[num_2] * 2 < ugly_number[num_3] * 3)
        {
            min_value = ugly_number[num_2] * 2;
        }
        else
        {
            min_value = ugly_number[num_3] * 3;
        }
        if (ugly_number[num_5] * 5 < min_value)
        {
            min_value = ugly_number[num_5] * 5;
        }

        // 동시에 같은 min나오는 경우 인덱스 증가를 위한 if 식들
        if (ugly_number[num_2] * 2 == min_value)
        {
            num_2++;
        }
        if (ugly_number[num_3] * 3 == min_value)
        {
            num_3++;
        }
        if (ugly_number[num_5] * 5 == min_value)
        {
            num_5++;
        }
        ugly_number[i] = min_value;
    }
   
    cout << min_value << endl;

    return 0;
} 
​
