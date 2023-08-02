#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
int main(void)
{
	size_t i = 0;
	int count = 0;
	char string[30 + 1];
	
	cin >> string;

	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] == '(') {
			count++;
		}
		if (string[i] == ')') {
			count--;
		}
		if (count < 0) { /* 괄호 갯수는 맞아도, )이것이 더 많아 지는 경우가 생기면 괄호가 닫히지 않고 끝나는 경우가 생기므로 체크 */
			break; 
		}
	}

	if (count == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
