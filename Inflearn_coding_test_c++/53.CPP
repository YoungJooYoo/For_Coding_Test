#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

size_t stack[100];
int top = -1;

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    return stack[top--];
}


int main(void) 
{
    //freopen("input.txt", "rt", stdin);
    size_t n, k;
    string str = "0123456789ABCDEF";

    cin >> n >> k;

    while (n > 0) {
        push(n % k);
        n = n / k;
    }
    
    while (top != -1) {
        cout << str[pop()];
    }

    return 0;
} 
