#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

size_t array_number[11];
size_t total = 0; // 배열의 전체값의 합 구한다.  합 - 부분집한 = 나머지 부분집합의 크기에 사용
size_t n;
bool flag = false;

void solution_dfs(size_t tree_level, size_t sum)
{
    if (sum > (total / 2)) 
    {
        return;
    }
    if (flag == true)
    {
        return;
    }

    if (tree_level == n + 1) // 종료지점 트리의 레벨과 N + 1값이 같으면 탐색 종료
    {
        // 부분 집합의 원소들의 총합
        if (sum == (total - sum))
        {
            flag = true;
        }
    }
    else
    {
        solution_dfs(tree_level + 1, sum + array_number[tree_level]);
        solution_dfs(tree_level + 1, sum);
    }
}

int main(void) 
{
    //freopen("input.txt", "rt", stdin);

    cin >> n;
    for (size_t i = 1; i <= n; i++) 
    {
        cin >> array_number[i];
        total = total + array_number[i];
    }

    solution_dfs(1, 0); // dfs 탐색 1부터 시작, sum은 0부터 시작

    if (flag == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
} 
