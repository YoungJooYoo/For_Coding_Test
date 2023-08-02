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

size_t n;
size_t m;
size_t cnt;
size_t number_list[10 + 1];

void solution_dfs(const size_t tree_level, const int sum)
{
    // DFS 종료조건, 탐색 트리의 레벨(깊이)
    if (tree_level == n + 1) {
        // 찾는값 m이 나올때 마다 카운팅
        if (sum == m) {
            cnt++;
        }
    }
    else {
        solution_dfs(tree_level + 1, sum + number_list[tree_level]); // 탐색깊이 + 1, 다음탐색깊이 = 다음배열 원소, 다음 원소 배열의 값을 + 경우
        solution_dfs(tree_level + 1, sum - number_list[tree_level]); // 탐색깊이 + 1, 다음탐색깊이 = 다음배열 원소, 다음 원소 배열의 값을 - 경우
        solution_dfs(tree_level + 1, sum); // 다음 원소 배열 덧샘 뺄셈 선택하지 않는 경우
        
    }
}

int main(void) 
{
    // freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);
    
    for (size_t i = 1; i <= n; i++) {
        scanf("%d", &number_list[i]);
    }
    
    solution_dfs(1, 0);

    // 한번도 카운트 안되면 -1 출력
    if (cnt == 0) {
        cout << "-1" << endl;
        return 0;
    }

    cout << cnt << endl;
 
    return 0;
} 
