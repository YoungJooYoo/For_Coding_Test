#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	size_t i;
	size_t year;
	char id_num[20];

	//freopen("input.txt", "rt", stdin);

	cin >> id_num; 

	/* 7번째 인덱스 값이 성별을 나타낸다. */
	if (id_num[7] == '1') {
		year = 1900 + ((id_num[0] - 48) * 10) + (id_num[1] - 48); /* char형에서 0은 48값, 48빼야지 일반 정수나옴 */
		cout << 2019 - year + 1 << " ";
		cout << "M" << endl;
	}
	if (id_num[7] == '2') {
		year = 1900 + ((id_num[0] - 48) * 10) + (id_num[1] - 48); /* char형에서 0은 48값, 48빼야지 일반 정수나옴 */
		cout << 2019 - year + 1 << " ";
		cout << "W" << endl;
	}
	if (id_num[7] == '3') {
		year = 2000 + ((id_num[0] - 48) * 10) + (id_num[1] - 48); /* char형에서 0은 48값, 48빼야지 일반 정수나옴 */
		cout << 2019 - year + 1 << " ";
		cout << "M" << endl;
	}
	if (id_num[7] == '4') {
		year = 2000 + ((id_num[0] - 48) * 10) + (id_num[1] - 48); /* char형에서 0은 48값, 48빼야지 일반 정수나옴 */
		cout << 2019 - year + 1 << " ";
		cout << "W" << endl;
	}

	return 0;
}
