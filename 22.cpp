#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int temperature[100000 + 1];

int main(void)
{
	int n;
	size_t k;
	size_t i;
	size_t j;
	int sum = 0;
	int max = -2147000000;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &temperature[i]);
	}

	for (i = 0; i < k; i++) {
		sum = sum + temperature[i];
	}
	
	max = sum;

	for (i = k; i < n; i++) {
		sum = sum + (temperature[i] - temperature[i - k]);
		if (sum > max) {
			max = sum;
		}
	}

	printf("%d\n", max);

    return 0;
}
