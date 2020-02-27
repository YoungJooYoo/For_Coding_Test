/* 1149_RGB거리 */
#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>

int MIN(int a, int b) {
    return a < b ? a : b;
}

int main(void) {

    int DP[1001][3] = { 0, }; //0 R, 1 G, 2 B   
    int cost[1001][3] = { 0, };
    int n;
    size_t i;

    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    for (i = 1; i <= n; ++i) {
        DP[i][0] = MIN(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
        DP[i][1] = MIN(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
        DP[i][2] = MIN(DP[i - 1][0], DP[i - 1][1]) + cost[i][2];
    }

    printf("%d\n", MIN(MIN(DP[n][0], DP[n][1]), DP[n][2]));

	return 0;
}
