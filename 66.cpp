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

// 인접리스트 풀이
int check[30];
size_t cnt = 0;
size_t n;

vector<int> map[30];

void dfs(int vertex)
{
    if (vertex == n) 
    {
        cnt++;
    }
    else
    {
        for (size_t i = 0; i < map[vertex].size(); i++)
        {
            if (check[map[vertex][i]] == 0)
            {
                check[map[vertex][i]] = 1;
                dfs(map[vertex][i]);
                check[map[vertex][i]] = 0;
            }
        }
    }
}

int main(void) 
{
    // freopen("input.txt", "rt", stdin);
    
    int m, i, a, b;
    
    cin >> n >> m;

    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        map[a].push_back(b); // 인집리스트 생성
    }

    check[1] = 1; // 1번 노드 방문체크
    dfs(1); // 1번 노트부터 시작

    cout << cnt << endl;

    return 0;
} 
