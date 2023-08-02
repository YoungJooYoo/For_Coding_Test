#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
    size_t n;
    size_t number;
    size_t answer;
    size_t result[11] = { 0, };
    size_t i;
   
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> number;
        cin >> answer;

        /* 1 + 2 + ·····+ n = n(n+1) / 2, 고등학교떄 배운 공식 */
        result[i] = (number * (number + 1)) / 2;

        if (result[i] != answer) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
 
	return 0;
}
