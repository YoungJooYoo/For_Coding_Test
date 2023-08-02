/* 백준 10039 평균점수 */
#include <iostream>

using namespace std;

int main(void)
{
    size_t i;
    size_t student_score[5];
    size_t average_score = 0;
    
    for (i = 0; i < 5; i++) {
        cin >> student_score[i];
        if (student_score[i] < 40) {
            student_score[i] = 40;
        }
        average_score = average_score + student_score[i];
    }
    
    cout << (average_score / 5) << endl;
    
    return 0;
}
