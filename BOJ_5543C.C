/* 백준 5543 상근날드 */
#include <iostream>
using namespace std;

int main(void)
{
    size_t i;
    size_t j;
    size_t min_price = 99999999999;
    size_t menu[3];
    size_t beverage[2];
    
    for (i = 0; i < 3; i++) {
        cin >> menu[i];
    }
    for (i = 0; i < 2; i++) {
        cin >> beverage[i];
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (min_price > menu[i] + beverage[j]) {
                min_price = menu[i] + beverage[j];
            }
        }
    }
    
    cout << min_price - 50 << endl;
    
    return 0;;
}
