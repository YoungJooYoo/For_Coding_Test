#pragma warning(disable:4996)
#include <iostream>

using namespace std;

void do_DFS(size_t n, size_t k)
{
    if (n > k) {
        return;
    }
    cout << n << " ";
    do_DFS(2 * n, k);
    do_DFS(2 * n + 1, k);
}

int main(int argc, const char * argv[]) 
{
    size_t n;
    size_t k;
    
    cin >> n >> k;
    do_DFS(n, k);
  
    return 0;
}
