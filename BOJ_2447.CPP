/* 백준 2447 별 찍기 - 10 */
#include <iostream>

using namespace std;

char map[3000][3000];
 
/* 배열을 공백으로 초기화 */
void init_map()
{
    for (int i = 0; i < 3000; ++i) {
        for (int j = 0; j < 3000; ++j) {
            map[i][j] = ' ';
        }
    }
}

/* 재귀로 별찍기 해결, 핵심은 행렬의 중앙이 비게 만드는 것! */
void solve(size_t n, size_t col, size_t raw)
{
    size_t div = n / 3;
    
    /* n = 1 인경우만 */
    if (n == 1) {
        map[col][raw] = '*';
        return;
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }
            solve(div, col + (div * i), raw + (div * j));
        }
    }
    return;
}

/* 결과 출력 */
void print_result(size_t n)
{
    size_t i;
    size_t j;
    
   for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}



int main(void)
{
    size_t n;
    
    cin >> n;
    
    init_map();
    solve(n, 0, 0);
    print_result(n);
    
    return 0;
}
