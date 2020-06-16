#include <iostream>
#include <stdio.h>

using namespace std;

int numbers[100];

int main(void)
{
    size_t i;
    size_t j;
    size_t n;
    int temp;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
