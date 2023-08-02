#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	size_t i;
	size_t result = 0;
	size_t measure_count = 0;
	char string[20];
	
	//freopen("input.txt", "rt", stdin);

	scanf("%s", string);

	/* 숫자 0 ~ 9 즉 아스키코드 48 ~ 57 사이 값만 보는 것 */
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] >= 48 && string[i] <= 57) {
			result = (result * 10) + (string[i] - 48); /* 10곱해서 자리수 늘려주고, -48 아스키코드 값 빼야 정수 */
		}
	}

	for (i = 1; i <= result; i++) {
		if (result % i == 0) {
			measure_count++;
		}
	}

	printf("%u\n", result);
	printf("%u\n", measure_count);

	return 0;
}
