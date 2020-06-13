#include <iostream>
#include <stdio.h>

using namespace std;

char carbon_and_hydrogen[1000];

int main(void)
{
	// freopen("input.txt", "rt", stdin);
    size_t i;
	size_t count_hydro = 0;
	size_t count_carbon = 0;
	size_t result = 0;
	size_t pos;

	cin >> carbon_and_hydrogen;

	// 탄소의 갯수 구하기
	if (carbon_and_hydrogen[1] == 'H') {
		count_carbon = 1; // C개 1개면 숫자없이 바로 H 나오므로
		pos = 1; // H의 인덱스 위치
	}
	else {
		for (i = 1; carbon_and_hydrogen[i] != 'H'; i++) {
			count_carbon = (count_carbon * 10) + (carbon_and_hydrogen[i] - 48); // 자리수 더할때마다 10씩 곱해 자리수 맞추고, 아스키 0인 48빼서 숫자화
		}
		pos = i; // H의 위치
	}

	// 수소의 갯수 구하기, H위치 + 1이 숫자시작
	if (carbon_and_hydrogen[pos + 1] == '\0') {
		count_hydro = 1;
	}
	else {
		for (i = pos + 1; carbon_and_hydrogen[i] != '\0'; i++) {
			count_hydro = (count_hydro * 10) + (carbon_and_hydrogen[i] - 48); // 자리수 더할때마다 10씩 곱해 자리수 맞추고, 아스키 0인 48빼서 숫자화
		}
	}

	cout << count_carbon * 12 + count_hydro << endl;

    return 0;
}
