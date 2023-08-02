#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

size_t sequence[100 + 2];
size_t check[100 + 2];

int main(void)
{
	size_t n;
	size_t i;
	size_t j;
	int index = 0;

	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> sequence[i];
	}

	for (i = 1; i <= n - 1; i++) {
		index = sequence[i] - sequence[i + 1];
		if (index < 0) {
			index = ~index + 1; /* 2의 보수법으로 음수를 양수로 만든다. */
		}
		if (index > 0 && index < n && check[index] == 0) {
			check[index]++;
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

    return 0;
}
