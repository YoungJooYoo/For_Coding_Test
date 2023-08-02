#include <iostream>

using namespace std;

int main(void) 
{
	size_t n;
	size_t m;
	size_t i;
	size_t sum = 0;

	cin >> n >> m;

	for (i = 0; i <= n; i++) {
		if (i % m == 0) {
			sum = sum + i;
		}
	}
	
	cout << sum << endl;

	return 0;
}
