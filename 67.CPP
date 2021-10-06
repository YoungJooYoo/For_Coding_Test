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

size_t map[30][30];
size_t check[30]; // 경로 방문 유무 체크
size_t n, m;
size_t result_cost = 2147000000;

void DFS(size_t vertex, size_t sum)
{
    if (vertex == n) // 정점의 수에 도달하면, 끝지점에 도착하면
    {
        if (result_cost > sum)
        {
            result_cost = sum;
        }
    }
    else
    {
        for (size_t i = 1; i <= n; i++)
        {
            if (map[vertex][i] > 0 && check[i] == 0)  // 가중치 값이 0보다 크면 정점이 연결 된 것 + 방문안된 조건
            {
                check[i] = 1;
                DFS(i, sum + map[vertex][i]);
                check[i] = 0;
            }
        }
    }

    
}

int main(void) 
{
    // freopen("input.txt", "rt", stdin);
   
    size_t row, column, weight;
    cin >> n >> m;
    
    for (size_t i = 0; i < m; i++)
    {
        cin >> row >> column >> weight;
        map[row][column] = weight;
    }
    
    check[1] = 1; // 1번 정점 출발
    DFS(1, 0); // 1번부터 DFS 시작

    cout << result_cost << endl;

    return 0;
} 
