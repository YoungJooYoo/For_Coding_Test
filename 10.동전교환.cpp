#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

int memoization[50000];

int main(void)
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);

	size_t n;
	size_t m;

	cin >> n;
	vector<int> coin(n);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cin >> m;
	vector<int> dy(m + 1, 1000);
	dy[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= m; j++) {
			dy[j] = min(dy[j], dy[j - coin[i]] + 1);
		}
	}

	cout << dy[m];

    return 0;
}
