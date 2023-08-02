#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

size_t numbers_1[100];
size_t numbers_2[100];
size_t merged_numbers[200];

void get_number(size_t numbers[], size_t n);
void merge_number(size_t n, size_t m);
void print_array(size_t n, size_t m);

int main(void)
{
    // freopen("input.txt", "rt", stdin);
    size_t n;
    size_t m;

    cin >> n;
    get_number(numbers_1, n);
    cin >> m;
    get_number(numbers_2, m);
    merge_number(n, m);
    sort(merged_numbers, merged_numbers + n + m);
    print_array(n, m);

    return 0;
}

void get_number(size_t numbers[], size_t n)
{
    for (size_t i = 0; i < n; i++) {
        cin >> numbers[i];
    }
}

void merge_number(size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++) {
        merged_numbers[i] = numbers_1[i];
    }
    for (size_t i = n; i < n + m; i++) {
        merged_numbers[i] = numbers_2[i - n];
    }
}

void print_array(size_t n, size_t m)
{
    for (size_t i = 0; i < n + m; i++) {
        cout << merged_numbers[i] << " ";
    }
}
