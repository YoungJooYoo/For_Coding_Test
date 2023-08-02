#include <iostream>

using namespace std;

int main(void)
{
	size_t n;
	size_t i;
	size_t sum = 0;

	cin >> n;
	cout << "1"; /* 1은 모든수의 약수 */

	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			cout << " + " << i;
			sum = sum + i;
		}
	}

	cout << " = ";
	cout << sum + 1 << endl; /* 모든 수의 약수 1을 마지막에 더한다. 5*/

	//system("pause"); /* 비주얼스튜디오 realse exe에서 이것 없으면 자꾸 종료되어서 결과 안보임 */

	return 0;
}
