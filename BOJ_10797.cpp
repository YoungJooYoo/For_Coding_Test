/* 백준 10797 10부제 */
#include <iostream>

using namespace std;

 int main(void)
 {
    size_t car_num[5];
    size_t num;
    size_t count = 0;
    size_t i;
    
    cin >> num;
    
    for (i = 0; i < 5; i++) {
        cin >> car_num[i];
        if (car_num[i] == num) {
            count++;
        }
    }
     
    cout << count << endl;
     
    return 0;
}
