#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    size_t i;
    size_t n;
    size_t temp;
    size_t digit;
    size_t count = 0;

    cin >> n;

    for (i = 1; i <= n; i++) {
        temp = i;

        while (temp > 0) {
            digit = temp % 10;
            if (digit == 3) {
                count++;
            }
            temp = temp / 10; 
        }
    }

    cout << count << endl;

    return 0;
}
