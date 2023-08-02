#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

int main(void)
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);
    
    size_t n;
    size_t m;
    int weight;
    int value;
    
    cin >> n >> m;

    vector<int> dp(m + 1, 0);

    for (size_t i = 0; i < n; i++) {
        cin >> weight >> value;
        for (size_t j = weight; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - weight] + value); // 기존값과 새로운 값 value + 현재무게 빼고 남은 무게가 해당하는 무게값
        }
    }
    
    cout << dp[m] << endl;

    return 0;
}
