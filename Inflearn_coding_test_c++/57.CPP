#pragma warning(disable:4996)
#include <iostream>

using namespace std;

void solution(size_t n)
{
    if (n == 0)
    {
        return;
    }
    solution(n / 2);
    cout << n % 2;
}

int main(void) 
{
    //freopen("input.txt", "rt", stdin);
    size_t n;
  
    cin >> n;
    solution(n);

    return 0;
} 
