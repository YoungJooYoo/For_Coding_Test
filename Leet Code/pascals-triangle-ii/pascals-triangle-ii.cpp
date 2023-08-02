class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0); // 0으로 초기화된 벡터 생성
        row[0] = 1; // 가장 첫번째 요소는 항상 1로 고정됨을 알 수 있다.
        
        // 2중 포문으로  4번째 줄의 값이 필요하면, 1, 2, 3 줄의 row 계산해서 사용
        for(size_t i = 1; i <= rowIndex; i++) {
            for(size_t j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        // 2중 for문 맨 위의 포문이 실행 될때마다 아래 중첩된 포문으로
        // row[1]원소부터 하나씩 구하고, row[2]구하고 row[3] 하나씩 구하는 방식
        
        return row;
    }
};