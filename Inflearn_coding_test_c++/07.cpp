#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	size_t i = 0;
	char string[100 + 1];
	const char* p_string = string;

	//freopen("input.txt", "rt", stdin);

	fgets(string, 101, stdin);

	while (*p_string != '\n') {
		if (*p_string >= 65 && *p_string <= 90) {
			printf("%c", *p_string + 32); /* 아스키코드 대문자라면, 소문자로 변경 하기*/
		}
		if (*p_string >= 97 && *p_string <= 122) {
			cout << *p_string;
		}
		p_string++;
	}

	return 0;
}
