#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;

size_t orangetree_map_size[50][50];

int main(int argc, const char * argv[]) {
    //freopen("test.txt", "rt", stdin);
    size_t i, j, k, l; // 4충 for문 index
    size_t orangemap_row; // 오렌지 맵의 가로 사이즈
    size_t orangemap_column; // 오렌지 맵의 세로 사이즈
    size_t territory_row; // 영역의 가로
    size_t territory_column; // 영역의 세로
    size_t max_value = 0; // 오렌지 나무의 최대 갯수
    size_t sum = 0;
    
    cin >> orangemap_row >> orangemap_column; // 오렌지 맵의 가로/세로 사이즈 입력 받기
    for (i = 0; i < orangemap_row; i++) { /* 오렌지 나무 맵에 값들 입력 받기 */
        for (j = 0; j < orangemap_column; j++) {
            cin >> orangetree_map_size[i][j];
        }
    }
    cin >> territory_row >> territory_column; // 영역의 가로/세로 사이즈 입력 받기
    
    /* 주어진 맵을 전체 탐색해서 가장 큰 값을 찾아간다. */
    for (i = 0; i < orangemap_row - territory_row + 1; i++) {  // 맵의 행
        for (j = 0; j < orangemap_column - territory_column + 1; j++) { // 맵의 열
            sum = 0; // sum을 초기화
            for (k = i; k < territory_row + i; k++) { // 받은 땅의 행
                for (l = j; l < territory_column + j; l++) { // 받은 땅의 열 //
                    sum = sum + orangetree_map_size[k][l]; // 영토에 내부값 전부 합산
                }
            }
            if (sum > max_value) { /* 최대값 찾기 */
                max_value = sum;
            }
        }
    }

    cout << max_value << endl;
    
    return 0;
}
