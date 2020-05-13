#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    size_t i;
    size_t n;
    size_t student[100 + 1];
    size_t max;
    size_t count = 0;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> student[i];
    }

    max = student[n - 1]; /* 마지막 학생의 값이 최대값 */
    
    for (i = n - 1; n >= 0; n--) {
        if (student[i] > max) {
            max = student[i];
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
