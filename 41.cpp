#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int n;
    int i;
    int temp;
    int number = 1;
    size_t count = 0;
    
    cin >> n;
    temp = n;
    n = n -1; /* 1을 빼고도 가능한지 알아보기 위함 */
    
    while (n > 0) {
        number++; /* number를 2부터 시작해 순차 증가하게 만든다. */
        n = n - number; /* 주어진 n에서 1빼고, 증가하는 number를 순차적으로 증가시켜 뺀다.*/
        
        if (n % number == 0) {
            for (i = 1; i < number; i++) {
                cout <<  n / number + i << " + ";
            }
            cout << n / number + i << " = " << temp << endl;
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}

