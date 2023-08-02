#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;

void get_numbers(int numbers[], size_t n);
void sort_selection(int numbers[], size_t n);
void print_array(size_t n);

int numbers[100];

int main(void)
{
    size_t n;

    cin >> n;
    get_numbers(numbers, n);
    sort_selection(numbers, n);
    print_array(n);

    return 0;
}

void get_numbers(int numbers[], size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }
}

void sort_selection(int numbers[], size_t n)
{
    int i;
    int j;
    int temp;

    for (i = 1; i < n; i++) {
        temp = numbers[i];
        for (j = i - 1; j >= 0 ; j--) {
            if (numbers[j] > temp) {
                numbers[j + 1] = numbers[j];
            }
            else {
                break;
            }
        }
        numbers[j + 1] = temp;
    }
}

void print_array(size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
}
