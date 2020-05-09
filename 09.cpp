#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
int main(void)
{
	size_t i;
	size_t j;
	size_t n;
	size_t measure_count[50000 + 1] = {0, };
	
	cin >> n;

	/* 문제해결 전략 : 시간을 줄이기 위해 배열에 약수의 개수를 저장한다.
	   단,  1의 배수만 카운트, 2의 배수만 카운트, 3의 배수만 카운트 -> 1000의 배수만 카운트로 카운팅을 줄인다.*/
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j = j + i) {
			measure_count[j]++;
		}
	}

	for (i = 1; i <= n; i++) {
		cout << measure_count[i] << " ";
	}

	return 0;
}
