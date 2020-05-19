#include <iostream>
#include <stdio.h>

#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	size_t n;
	size_t i;
	size_t j;
	size_t score[100 + 1];
	size_t rank[100 + 1];
	size_t count = 1;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> score[i];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (score[i] < score[j]) {
				count++;
			}
		}
		rank[i] = count;
		count = 1;
	}

	for (i = 0; i < n; i++) {
		cout << rank[i] << " ";
	}

	return 0;
}
