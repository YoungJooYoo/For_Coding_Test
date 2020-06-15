#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

size_t numbers[100];

void swap(size_t numbers[100], size_t i, size_t idx)
{
    size_t temp;
    temp = numbers[i];
    numbers[i] = numbers[idx];
    numbers[idx] = temp;
}

int main(void)
{
	// freopen("input.txt", "rt", stdin);
    size_t i;
    size_t j;
    size_t n;
    size_t idx; // 최소값을 가지는 index를 저장한다.
    
    
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (i = 0; i < n; i++) {
        idx = i;
        for (j = i; j < n; j++) {
            if (numbers[j] < numbers[i]) {
                idx = j;
            }
        }
        swap(numbers, i, idx);
    }

    for (i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
