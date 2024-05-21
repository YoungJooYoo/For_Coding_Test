class Solution 
{
public:
    int oddCells(const int m, const int n, const vector<vector<int>>& indices) 
    {
        // 각 행과 열의 증가 횟수를 기록할 벡터 초기화
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        
        // indices 배열에 따라 증가 횟수 기록
        for (const auto& index : indices) 
        {
            const int ri = index[0];
            const int ci = index[1];
            ++row_count[ri];
            ++col_count[ci];
        }
        
        
        // 각 셀의 최종 값을 계산하고 홀수인지 체크
        int odd_count = 0;
        for (size_t i = 0; i < m; ++i) 
        {
            for (size_t j = 0; j < n; ++j) 
            {
                if ((row_count[i] + col_count[j]) % 2 == 1) {
                    ++odd_count;
                }
            }
        }
        
        return odd_count;
    }
};

// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/description/

/*
### 문제 번역

**1252. 홀수 값 셀을 가진 행렬**

난이도: 쉬움

힌트:
m x n 크기의 행렬이 초기값 0으로 주어집니다. 또한, 2차원 배열 `indices`가 주어지는데, `indices[i] = [ri, ci]`는 0부터 시작하는 위치를 나타내며 이 위치에서 행렬에 다음과 같은 증분 연산을 수행합니다.

각 `indices[i]`에 대해 다음 두 작업을 모두 수행합니다:
1. 행 `ri`에 있는 모든 셀을 증가시킵니다.
2. 열 `ci`에 있는 모든 셀을 증가시킵니다.

주어진 `m`, `n`과 `indices`를 사용하여 모든 증분 연산을 수행한 후 홀수 값인 셀의 개수를 반환하세요.

### 예제

**예제 1:**

입력: `m = 2, n = 3, indices = [[0,1],[1,1]]`

출력: `6`

설명: 초기 행렬 = [[0,0,0],[0,0,0]].
첫 번째 증분 연산 후 [[1,2,1],[0,1,0]]가 됩니다.
최종 행렬은 [[1,3,1],[1,3,1]]이며, 홀수 값이 6개 있습니다.

**예제 2:**

입력: `m = 2, n = 2, indices = [[1,1],[0,0]]`

출력: `0`

설명: 최종 행렬은 [[2,2],[2,2]]이며, 홀수 값이 없습니다.

### 제약 조건

- `1 <= m, n <= 50`
- `1 <= indices.length <= 100`
- `0 <= ri < m`
- `0 <= ci < n`

### 추가 과제

O(n + m + indices.length) 시간과 O(n + m) 추가 공간만 사용하여 이 문제를 해결할 수 있나요?

### 문제 요약

m x n 크기의 초기값 0인 행렬이 주어집니다. 각 인덱스에 대해 특정 행과 열을 증가시키는 연산을 한 후, 최종 행렬에서 홀수 값인 셀의 개수를 구하는 문제입니다.

### 풀이 방향

1. 행렬 전체를 다루지 않고, 행과 열의 증가 횟수를 별도로 계산합니다.
2. `rows`와 `cols`라는 두 개의 배열을 사용하여 각 행과 열이 몇 번 증가되었는지를 기록합니다.
3. 최종적으로 각 셀의 값이 홀수인지 계산하여 결과를 구합니다.



### 설명

1. `row_count`와 `col_count` 배열을 초기화하여 각각의 행과 열의 증가 횟수를 기록합니다.
2. `indices` 배열을 순회하면서 각 행(`ri`)과 열(`ci`)에 해당하는 증가 횟수를 기록합니다.
3. 행렬의 각 셀을 순회하면서 최종 값이 홀수인 셀의 개수를 셉니다. `row_count[i] + col_count[j]`의 합이 홀수인 경우 해당 셀이 홀수입니다.
4. 최종적으로 홀수 값인 셀의 개수를 반환합니다.

이 코드는 O(m + n + indices.length) 시간 복잡도와 O(m + n) 공간 복잡도를 가지며, 제약 조건을 만족합니다.

*/
