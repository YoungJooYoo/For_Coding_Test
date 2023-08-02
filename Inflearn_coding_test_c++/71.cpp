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
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

int check[10001];
int direction[3] =  {1, -1, 5};

// 상태 트리를 만들어서 해결 앞으로 1칸, 뒤로 1칸, 5칸 앞으로 3가지 경우 상태 탐색
// BFS 문제 Queue 사용
int main(void) 
{
    // freopen("input.txt", "rt", stdin);
    size_t start_pos;
    size_t end_pos;
    int curr_pos;
    int x; // Q에서 꺼낼자료
    queue<int> Q;
    cin >> start_pos >> end_pos;

    check[start_pos] = 1; // 방문 체크
    Q.push(start_pos); // 출발지점 Q에 넣는다.

    while (!Q.empty())
    {
        x = Q.front(); // x는 +1 -1 +5 값이 계산된 결과가 큐에 들어 갔을때 하나씩 앞에서 뺴오는 값
        Q.pop();

        for (size_t i = 0; i < ARRAY_LENGTH; i++)
        {
            curr_pos = x + direction[i]; // 지금 위치에서 앞으로 1, 뒤로 -1, 앞으로 5 경우 계산
            
            if (curr_pos <= 0 || curr_pos > 10000)
            {
                continue;
            }
            if (curr_pos == end_pos)
            {
                cout << check[x]; // 시작지점을 1로 진행해서
                return 0;
            }
            if (check[curr_pos] == 0) // 아직 방문하지 않은 위치라면
            {
                check[curr_pos] = check[x] + 1; // 해당 위치 방문 표시 + 방문레벨  BFS 깊이 어디까지인지  check[6] : 2 5 + 1방문 깊이 레벨 2
                Q.push(curr_pos);
            }
        }
    }
      
    return 0;
} 
