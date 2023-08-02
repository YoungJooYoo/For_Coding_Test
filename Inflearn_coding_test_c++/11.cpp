#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;
 
int main(void)
{
    size_t n;
    size_t i;
    size_t temp;
    size_t count = 0;

    cin >> n;

    for (i = 1; i <= n; i++) {
        temp = i;

        while (temp > 0) {
            count++;
            temp = temp / 10;
        }
    }

    cout << count << endl;
   
	return 0;
}
