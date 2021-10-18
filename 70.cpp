#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

int check[30];
int distances[30];

int main(void) 
{
    int n, m, a, b, x; // 간선 정보 a b   큐에서 뺄 자료 x
    vector<int> map[30];
    queue<int> q;

    cin >> n >> m;

    for (size_t i = 1; i <= m; i++)
    {
        cin >> a >> b; // 간선 정보 a b 입력 받기
        map[a].push_back(b);
    }

    q.push(1); // 1번 간선부터 bfs 탐색 시작
    check[1] = 1; // 1번 간선 방문했다 표시

    // bfs 시작
    while (q.empty() != NULL)
    {
        x = q.front(); // q의 앞의 자료 x에 넣어줌
        q.pop();
        for (size_t i = 0; i < map[x].size(); i++)
        {
            if (check[map[x][i]] == 0)
            {
                check[map[x][i]] == 1; // 방문을 안했다면, 방문했다 표시
                q.push(map[x][i]);
                distances[map[x][i]] = distances[x] + 1;
            }
        }
    }

    for (size_t i = 2; i <= n; i++)
    {
        cout << i << " : " << distances[i] << endl;
    }

    return 0;
} 
