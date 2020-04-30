/* 백준 2822 점수계산 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void)
{
    size_t i;
    size_t total_score = 0;
    size_t sorted_index[5];
    vector<pair<size_t, size_t>> v_score(8);
    
    
    /* 점수랑, 인덱스를 쌍으로 넣어준다. */
    for (i = 0; i < 8; i++) {
        cin >> v_score[i].first;
        v_score[i].second = i + 1;
    }
    
    /* 오름차순 정렬 */
    sort(v_score.begin(), v_score.end(), greater<pair<size_t,size_t>>());

    for (i = 0; i < 5; i++) {
        total_score += v_score[i].first;
        sorted_index[i] = v_score[i].second;
    }

    sort(sorted_index , sorted_index + 5);

    cout << total_score << endl;
    
    for (i = 0; i < 5; i++) {
        cout << v_score[i].second << " ";
    }
    
    return 0;;
}


