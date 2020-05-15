#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;


size_t sequence[100000 + 1];

int main(void)
{
	size_t n;
	size_t i;
	size_t j;
	size_t count = 1; /* 시작인덱스를 카운트 1로 잡고 시작한다. */
	size_t max = 0;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	for (i = 0; i < n - 1; i++) {
		if (sequence[i] <= sequence[i + 1]){
			count++;
			if (count > max) {
				max = count;
			}
		}
		else {
			count = 1;
		}
	}

	cout << max << endl;

    return 0;
}
