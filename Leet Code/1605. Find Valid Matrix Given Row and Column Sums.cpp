class Solution 
{
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        const int m = rowSum.size();
        const int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 현재 셀에 할당할 수 있는 최대 값
                matrix[i][j] = min(rowSum[i], colSum[j]);
                // 할당 후 남은 합 업데이트
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }

        return matrix;
    }
};


/*

1605. 행과 열의 합이 주어진 유효한 행렬 찾기
중간 난이도

주제

기업

주어진 두 배열 rowSum과 colSum은 비음수 정수로 이루어져 있으며, 여기서 rowSum[i]는 2D 행렬의 i번째 행의 요소들의 합이고, colSum[j]는 j번째 열의 요소들의 합을 나타냅니다. 다시 말해, 행렬의 요소들은 알 수 없지만 각 행과 열의 합은 알고 있습니다.

rowSum.length x colSum.length 크기의 비음수 정수로 이루어진 행렬 중에서 rowSum과 colSum의 요구사항을 만족하는 임의의 행렬을 찾으세요.

요구사항을 충족하는 임의의 행렬을 나타내는 2D 배열을 반환하세요. 요구사항을 충족하는 적어도 하나의 행렬이 존재하는 것이 보장됩니다.

예제 1:
lua
코드 복사
입력: rowSum = [3,8], colSum = [4,7]
출력: [[3,0],
       [1,7]]
설명:

0번째 행: 3 + 0 = 3 == rowSum[0]
1번째 행: 1 + 7 = 8 == rowSum[1]
0번째 열: 3 + 1 = 4 == colSum[0]
1번째 열: 0 + 7 = 7 == colSum[1]
행과 열의 합이 일치하며, 모든 행렬 요소는 비음수입니다.

또 다른 가능한 행렬은 다음과 같습니다: [[1,2], [3,5]]

예제 2:
less
코드 복사
입력: rowSum = [5,7,10], colSum = [8,6,8]
출력: [[0,5,0],
       [6,1,0],
       [2,0,8]]
제약 사항:
1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 10^8
sum(rowSum) == sum(colSum)

*/
