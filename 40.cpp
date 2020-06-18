#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int numbers_1[30000 + 1];
int numbers_2[30000 + 1];
int merged_numbers[60000 + 1];
size_t merged_array_index;

void get_number(int numbers[], size_t n);
void merge_number(size_t n, size_t m);
void print_array();

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
    sort(merged_numbers, merged_numbers + merged_array_index);
    print_array();

    return 0;
}

void get_number(int numbers[], size_t n)
{
    for (size_t i = 0; i < n; i++) {
        cin >> numbers[i];
    }
}

void merge_number(size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (numbers_1[i] == numbers_2[j]) {
                merged_numbers[merged_array_index] = numbers_1[i];
                merged_array_index++;
            }
        }
    }
}

void print_array()
{
    for (size_t i = 0; i < merged_array_index; i++) {
        cout << merged_numbers[i] << " ";
    }
}
