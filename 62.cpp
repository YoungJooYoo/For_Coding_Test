#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

int arr_data[100];
int arr_temp[100];


void divide(int begin, int end)
{
    int mid;
    int p1;
    int p2;
    int p3;

    if (begin < end) 
    {
        mid = (begin + end) / 2;

        // 배열을 작은 조각으로 분해하는 과정
        // 각각의 1개 원소만큼 분해가 되고, 여긱까지 분해되면 아무일 하지 않고 return
        // 실질적 정렬은 [1.2] 처럼 2개의 원소를 가지고 쪼개진 배열부터 정렬시작
        divide(begin, mid);
        divide(mid + 1, end);

        // 분해된 배열부터 정렬시작
        p1 = begin;
        p2 = mid + 1;
        p3 = begin;
        while (p1 <= mid && p2 <= end)
        {
            if (arr_data[p1] < arr_data[p2])
            {
                arr_temp[p3] = arr_data[p1];
                p1++;
                p3++;
            }
            else
            {
                arr_temp[p3] = arr_data[p2];
                p3++;
                p2++;
            }
        }
        // 정렬이끝나고 남은배열이 있을경우 주르륵 넣어준다.
        while (p1 <= mid)
        {
            arr_temp[p3] = arr_data[p1];
            p1++;
            p3++;
        }
        while (p2 <= end)
        {
            arr_temp[p3] = arr_data[p2];
            p2++;
            p3++;
        }
        for (size_t i = begin; i <= end; i++)
        {
            arr_data[i] = arr_temp [i];
        }
    }
    
}

int main(void) 
{
    freopen("input.txt", "rt", stdin);
    
    size_t n;
    
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> arr_data[i];
    }

    divide(1, n);

    for (size_t i = 1; i <= n; i++)
    {
        cout << arr_data[i] << " ";
    }

 
    return 0;
} 
