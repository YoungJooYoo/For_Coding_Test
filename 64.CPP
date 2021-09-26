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

int map[30][30];
int visited_place[30];
size_t cnt = 0;
size_t n;
size_t m;

void DFS(int vertex)
{
    if (vertex == n) // 종료 지점, 종료조건
    {
        cnt++;
    }
    else
    {
        for (size_t i = 1; i <= n; i++)
        {
            if (map[vertex][i] == 1 && visited_place[i] != 1) // 맵의 이 지역을 방문이 가능한지 체크, 방문하지 않은지역만 방문
            {
                visited_place[i] = 1;
                DFS(i);
                visited_place[i] = 0;  // 방문을 풀어주는 이유 : 재귀하다가 방문 안풀어주면 다음 방문시 경로 못찾는다.
            }
        }
    }
}

int main(void) 
{
    //freopen("input.txt", "rt", stdin);
    
    size_t row;
    size_t column;
    
    cin >> n >> m;
  
    for (size_t i = 1; i <= m; i++)
    {
        cin >> row >> column;
        map[row][column] = 1; // 인접행렬 생성
    }
    
    visited_place[1] = 1; // 1번 정점은 방문했다고 체크
    DFS(1); // 1번 정점 출발

    cout << cnt << endl;

    return 0;
} 
