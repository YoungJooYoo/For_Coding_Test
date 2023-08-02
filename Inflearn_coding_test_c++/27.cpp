#include <iostream>
#include <stdio.h>

using namespace std;

size_t prime_number[1000 + 1];

int main(void)
{
    size_t i;
    size_t j;
    size_t n;
    size_t temp;
   
    cin >> n;

    /* 소수는 2부터 시작 */
    for (i = 2; i <= n; i++) {
        temp = i;
        j = 2;
        while (true) {
            if (temp % j == 0) {
                temp = temp / j;
                prime_number[j]++;
            }
            else {
                j++; 
            }
            if (temp == 1) {
                break;
            }
        }
    }

    cout << n << "! = ";
    for (i = 2; i <= n; i++) {
        if (prime_number[i] != 0) {
            cout << prime_number[i] << " ";
        }
    }

    return 0;
}
