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

vector<pair<size_t, size_t>> map[30];
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
        for (size_t i = 0; i < map[vertex].size(); i++)
        {
            if (check[map[vertex][i].first] == 0) // first 요소가 정점이므로, 정점 방문 했는지 check
            {
                check[map[vertex][i].first] = 1;
                DFS(map[vertex][i].first, sum + map[vertex][i].second);
                check[map[vertex][i].first] = 0;
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
        map[row].push_back(make_pair(column, weight));
    }
    
    check[1] = 1; // 1번 정점 출발
    DFS(1, 0); // 1번부터 DFS 시작

    cout << result_cost << endl;

    return 0;
} 
