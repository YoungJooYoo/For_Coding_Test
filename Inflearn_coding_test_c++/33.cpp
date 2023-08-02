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
    size_t idx; /* 최소값을 가지는 index를 저장한다. */
    size_t rank = 1; /* 등수 비교에 쓴다. count = 3이면 3등이란 의미. */
    
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (i = 0; i < n; i++) {
        idx = i;
        for (j = i; j < n; j++) {
            if (numbers[j] > numbers[idx]) {
                idx = j;
            }
        }
        swap(numbers, i, idx);
    }

    /* 중복되는 값을 체크하기 위해, 다를 경우만 count++를 하고 count = 3 즉 3등인 경우 출력 */
    for (i = 1; i < n; i++) {
        if (numbers[i - 1] != numbers[i]) {
            rank++;
        }
        if (rank == 3) {
            cout << numbers[i] << endl;
            return 0;
        }
    }

    return 0;
}
