#include <iostream>

using namespace std;

int main(void) 
{
	size_t a;
	size_t b;
	size_t i;
	size_t sum = 0;

	cin >> a >> b;
	
	for (i = a; i <= b; i++) {
		cout << i << " + ";
		sum = sum + a;
		a++;
	}
	cout << i << " = ";
	cout << sum << endl;

	return 0;
}
