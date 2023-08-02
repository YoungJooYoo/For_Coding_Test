#include <iostream>
#include <stdio.h>
#define SCISSORS (1)
#define ROCK (2)
#define PAPER (3)

using namespace std;

int main(void)
{
    size_t i;
    size_t n;
    size_t a[100 + 1];
    size_t b[100 + 1];
    char result[100 + 1];

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cin >> b[i];

    }

    /* A가 비기는 경우, 이기는 경우만 찾고 나머지 경우는 전부 B가 이기는 것이다. */
    for (i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            result[i] = 'D';
        }
        else if (a[i] == ROCK && b[i] == SCISSORS) {
            result[i] = 'A';
        }
        else if (a[i] == PAPER && b[i] == ROCK) {
            result[i] = 'A';
        }
        else if (a[i] == SCISSORS && b[i] == PAPER) {
            result[i] = 'A';
        }
        else {
            result[i] = 'B';
        }
    }


    for (i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
