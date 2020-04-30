/* 백준 5565 영수증 */
#include <iostream>

using namespace std;

 int main(void)
 {
    size_t total_price = 0;
    size_t book_price[9];
    size_t i;
     
    cin >> total_price;
 
     for(i = 0; i < 9; i++) {
         cin >> book_price[i];
         total_price = total_price - book_price[i];
    }

    cout << total_price << endl;
     
    return 0;
}
