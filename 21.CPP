#include <iostream>
#include <stdio.h>
#define A (1)
#define B (2)

using namespace std;

int main(void)
{
    size_t i;
    size_t a[10 + 1];
    size_t b[10 + 1];
    size_t score_a = 0;
    size_t score_b = 0;
    size_t winner = 0;

    for (i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (i = 0; i < 10; i++) {
        cin >> b[i];
    }

    for (i = 0; i < 10; i++) {
        if (a[i] == b[i]) {
            score_a++;
            score_b++;
        }
        else if (a[i] > b[i]) {
            score_a = score_a + 3;
            winner = A;
        }
        else if (b[i] > a[i]) {
            score_b = score_b + 3;
            winner = B;
        }
    }

    cout << score_a << " " << score_b << endl;

    if (score_a == score_b) {
        if (winner == 0) {
            cout << "D" << endl;
        }
        else if (winner == A) {
            cout << "A" << endl;
        }
        else if (winner == B) {
            cout << "B" << endl;
        }
    }
    else if (score_a > score_b) {
        cout << "A" << endl;
    }
    else if (score_a < score_b) {
        cout << "B" << endl;
    }

    return 0;
}
