class Solution 
{
public:
    int maxDistance(const vector<vector<int>>& arrays) 
    {
        const size_t LENGTH = arrays.size();
        int longestDistance =  numeric_limits<int>::min();
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();

        for (size_t i = 1; i < LENGTH; ++i)
        {
            longestDistance = max(longestDistance, abs(minVal - arrays[i].back()));
            longestDistance = max(longestDistance, abs(maxVal - arrays[i].front()));
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }

        return longestDistance;
    }
};

// https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16

/*

### 문제: 배열 간 최대 거리

여러 개의 배열이 주어지며, 각 배열은 오름차순으로 정렬되어 있습니다.

각 배열에서 하나씩 두 개의 정수를 선택하여 거리(두 정수의 절대 차이)를 계산할 수 있습니다. 이 때, 가능한 최대 거리를 반환하세요.

### 예제 1:

- 입력: `arrays = [[1,2,3],[4,5],[1,2,3]]`
- 출력: 4
- 설명: 최대 거리를 구하기 위해 첫 번째나 세 번째 배열에서 1을 선택하고, 두 번째 배열에서 5를 선택할 수 있습니다. 이 경우 최대 거리는 |1 - 5| = 4입니다.

### 예제 2:

- 입력: `arrays = [[1],[1]]`
- 출력: 0
- 설명: 두 배열 모두 같은 값만 가지므로 최대 거리는 0입니다.

### 제약 조건:

- `m == arrays.length`
- `2 <= m <= 105`
- `1 <= arrays[i].length <= 500`
- `-104 <= arrays[i][j] <= 104`
- 각 배열은 오름차순으로 정렬되어 있습니다.
- 모든 배열의 정수 개수는 최대 105개입니다.
*/
