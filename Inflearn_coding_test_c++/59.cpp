#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

size_t mask_tree[10 + 1];
size_t tree_level;
size_t n;

void dfs(size_t tree_level)
{
    size_t i;
    
    // 종료조건, 탐색하는 트리 레벨이 종료 조건 만족할때
    if (tree_level == n + 1) {
        for (i = 1; i <= n; i++) {
            if (mask_tree[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    mask_tree[tree_level] = 1;
    dfs(tree_level + 1);
    mask_tree[tree_level] = 0;
    dfs(tree_level + 1);
}

int main(int argc, const char * argv[]) {
    //freopen("test.txt", "rt", stdin);
    
    cin >> n;
    dfs(1);
  
    return 0;
}
