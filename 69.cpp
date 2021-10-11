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

int q[100];
int front = -1;
int back = -1;
int check[10];
vector<int> map[10];

int main(void) 
{
    // freopen("input.txt", "rt", stdin);
   
    size_t a, b, x;


    for (size_t i = 1; i <= 6; i++)
    {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    q[++back] = 1; // 루트 탐색, 1부터 넣기
    check[1] = 1; // 1번, 루트 방문

    // front = back이 같아지는 순간 더 뺼 자료가 없다.
    while (front < back)
    {
        x = q[++front];
        cout << x << " ";
        
        for (size_t i = 0; i < map[x].size(); i++)
        {
            if (check[map[x][i]] == 0)
            {
                check[map[x][i]] = 1;
                q[++back] = map[x][i];
            }
        }
        
    }
    return 0;
} 
