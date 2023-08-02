#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	
    size_t i;
	size_t k = 1;
    size_t n;
	size_t left_number = 1;
	size_t right_number;
	size_t current_number;
	size_t result = 0;
	// freopen("input.txt", "rt", stdin);

    cin >> n;

	while (left_number != 0) {
		left_number = n / (k * 10);
		right_number = n % k;
		current_number = (n / k) % 10;
		if (current_number > 3) {
			result = result + ((left_number + 1) * k);
		}
		else if (current_number == 3) {
			result = result + ((left_number * k) + (right_number + 1));
		}
		else {
			result = result + (left_number * k);
		}
		k = k * 10;
	}

	cout << result << endl;
   
    return 0;
}
