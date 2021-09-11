#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

void print_number(size_t n)
{
    size_t m;
    m = n;
    
    if (n == 0)
    {
        cout << n << " ";
        return;
    }
    
    if (m != 1)
    {
        m = m - 1;
        print_number(m);
    }
    
    cout << n << " ";
}

int main(int argc, const char * argv[]) {
    //freopen("test.txt", "rt", stdin);
    size_t n;
    
    cin >> n;
    print_number(n);
   
    return 0;
}
