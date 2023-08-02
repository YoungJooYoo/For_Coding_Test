#include <iostream>
#include <stdio.h>
using namespace std;

void get_numbers(int numbers[], size_t n);
void sort_bubble(int numbers[], size_t n);
void split_numbers(int numbers[], size_t n); /* 양수, 음수 각각 다른 배열에 나누어 담기 */
void print_array();

int numbers[100];
int plus_numbers[100]; /* 양수만 저장할 배열 */
int minus_numbers[100]; /* 음수만 저장할 배열 */
size_t plus_array_index = 0;
size_t minus_array_index = 0;

int main(void)
{
    size_t n;
    
    cin >> n;
    get_numbers(numbers, n);
    split_numbers(numbers, n);
    sort_bubble(numbers, n);
    print_array();
    
    return 0;
}

void get_numbers(int numbers[], size_t n)
{
    size_t i;
    
    for (i = 0; i < n; i++) {
           cin >> numbers[i];
    }
}

void split_numbers(int numbers[], size_t n)
{
    size_t i;
    
    for (i = 0; i < n; i++) {
        if (numbers[i] > 0) {
            plus_numbers[plus_array_index] = numbers[i];
            plus_array_index++;
        }
        else {
            minus_numbers[minus_array_index] = numbers[i];
            minus_array_index++;
        }
    }
}

void sort_bubble(int numbers[], size_t n)
{
    size_t i;
    size_t j;
    int temp;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

void print_array()
{
    size_t i;
    
    for (i = 0; i < minus_array_index; i++) {
        cout << minus_numbers[i] << " ";
    }
    for (i = 0; i < plus_array_index; i++) {
           cout << plus_numbers[i] << " ";
    }
}
