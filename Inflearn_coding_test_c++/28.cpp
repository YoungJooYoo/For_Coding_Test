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
    size_t count_2 = 0;
    size_t count_5 = 0;

    cin >> n;

    /* n이 1000까지 들어온다. 따라서 계산해서 숫자 담는게 불가능하다. 
       따라서 소인수 분해를 진행하고,  2 * 5 = 10, 2와 5의 갯수를 파악하면
       0의 갯수를 알 수 있다.
    */
    
    for (i = 2; i <= n; i++) {
        temp = i;
        j = 2;

        while (true) {
            if (temp % j == 0) {
                if (j == 2) {
                    count_2++;
                }
                else if(j == 5) {
                    count_5++;
                }
                temp = temp / j;
            }
            else {
                j++;
            }
            if (temp == 1) { /* temp 가 1니 나온 것은 더 이상 나눌 것이 없다느 것 */
                break;
            }
        }
    }

    /* 2와 5의 갯수가 일치할때 0의 갯수 카운트 가능, 더 작게 카운트 된 것을 출력한다. */
    if (count_2 > count_5) {
        cout << count_5 << endl;
    }
    else {
        cout << count_2 << endl;
    }

   
    return 0;
}
