#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
bool isPrime(size_t x)
{
    size_t i;
    size_t count = 0;

    /* 소수는 약수가 2개뿐이므로, count가 2를 초과하면 약수가 아님 */
    for (i = 1; i <= x; i++) {
        if (x % i == 0) {
            count++;
        }
    }

    if (count == 2) {
        return true;
    }

    return false;
}

size_t reverse(size_t x)
{
    size_t temp = 0;
    size_t result = 0;

    while (x > 0) {
        temp = x % 10;
        result = (result * 10) + temp;
        x = x / 10;
    }

    return result;
}

int main(void)
{
    size_t n;
    size_t i;
    size_t temp;
    size_t number;

    cin >> n;
   
    for (i = 0; i < n; i++) {
        cin >> number;
        temp = reverse(number);
        if (isPrime(temp)== true){
            cout << temp << " ";
        }
    }

    
	return 0;
}
