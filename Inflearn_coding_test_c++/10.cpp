#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
int digit_sum(int x)
{
    int sum = 0;

    while (x > 0) {
        sum = sum + (x % 10);
        x = x / 10;
    }

    return sum;
}

int main(void)
{
    size_t n;
    size_t number;
    size_t i;
    size_t sum = 0;
    size_t max = 0;
    size_t result = 0;


    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> number;
        sum = digit_sum(number);
        if (sum > max) {
            max = sum;
            result = number;
        } else if (sum == max) {
            if (number > result) {
                result = number;
            }
        } 
    }

    cout << result << endl;

	return 0;
}

