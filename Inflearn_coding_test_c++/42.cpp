#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

size_t number[100000 + 1];

int main(void)
{
    size_t n;
    size_t i;
    size_t num;

    cin >> n >> num;

    for (i = 0; i < n; i++) {
        cin >> number[i];
    }

    sort(number, number + n);

    for (i = 0; i < n; i++) {
        if  (num == number[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
