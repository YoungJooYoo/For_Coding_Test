/* 2163 초콜릿 자르기 */
#include <iostream>
using namespace std;

size_t chocolate[301 * 301];

int main(void)
{
    size_t m;
    size_t n;
    
    cin >> m >> n;
    cout << (n * m) - 1 << endl; /* 그림을 그려보면 n*m-1 갯수의 패턴이 있음을 알 수 있다. */
    
    return 0;
}
