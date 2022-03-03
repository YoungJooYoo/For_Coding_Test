#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

int unf[1001];

int Find(int v) // v라는 학생번호가 넘어오면 집합 번호를 반환한다.
{
	if (v == unf[v]) {
		return v;
	}
	else { // 재귀로 연결된 노드를 찾는다.
		return unf[v] = Find(unf[v]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) { // union 합치는 부분이다.
		unf[a] = b;
	}
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);
	int i;
	int n;
	int m;
	int a;
	int b; 
	int fa;
	int fb;
	int j;

	scanf("%d %d", &n, &m);

	// 1차원 배열로 트리 형태 구현, 배열의 인덱스라 학생번호 배열이 값이 집합의 번호
	for (i = 1; i <= n; i++) {
		unf[i] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	scanf("%d %d", &a, &b);

	fa = Find(a);
	fb = Find(b);

	if (fa == fb) printf("YES\n"); 
	else printf("NO\n");

    return 0;
}

/*
배열의 인덱스와 값을 이요해 하나의 연결된 그래프를 만든다.
배열 1 2 3 4 5 6 7 8 9
원소 2 3 4 5 6 7 8 9 9

배열 1에 접근하면 2가 나오고, 2로 다시 배열에 접근하면 3이 나오는 방식으로
연결된 노드끼리 연결됨을 확인한다.


반대로

1 2 3 4
4 4 4 4
표기하면
4노드 기준으로 14 24 34 다 연결가능하고 노드의 깊이를 1로 만드는 방법도 있다.
*/
