#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
    size_t n; /* 수치를 10번 체크*/
    size_t m; /* 수치 기준은 M */
    size_t value;
    size_t max_second = 0;
    size_t count = 0;
    size_t i;
   
    cin >> n;
    cin >> m;

    for (i = 0; i < n; i++) {
        cin >> value;
        
        if (value > m) {
            count++;
            if (count > max_second) {
                max_second = count;
            }
        }
        if (value <= m) {
            count = 0;
        }
    }

    if (max_second == 0) {
        printf("-1\n");
    }
 
    cout << max_second << endl;

	return 0;
}
