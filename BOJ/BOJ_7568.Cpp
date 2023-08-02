/* 백준 7568 덩치 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(void) 
{
	int n;
	int body_info[60][3]; /* 0:키  1:몸무게  2:등수*/
	size_t i;
	size_t j;

	//freopen("input.text", "r", stdin); /* stdio.h 용 */
	//ifstream open("input.txt"); /* iostream 용 */

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> body_info[i][0];
		cin >> body_info[i][1];
		body_info[i][2] = 1;
	}

	/* 브루투스 포스, 모든 것을 비교한 후 등수를 체크한다. */
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) { /* 비교 대상이 나 자신인 경우*/
				continue;
			}
			/* 키, 몸무게 비교 시작 */
			if (body_info[i][0] < body_info[j][0] && body_info[i][1] < body_info[j][1]) {
				body_info[i][2]++;
			}
		}
		cout << body_info[i][2] << " ";
	}

	cout << endl;
	
	return 0;
}
