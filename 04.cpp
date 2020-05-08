#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	size_t n;
	size_t i;
	size_t age[100 + 1];

	cin >> n;
	
	for (i = 0; i < n; i++) {
		cin >> age[i];
	}

	sort(age, age + n);
	
	cout << age[n - 1] - age[0] << endl;

	return 0;
}
