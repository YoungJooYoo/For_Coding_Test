class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        int i;
        int j;
        int row = points.size();
        int col = points[0].size();
        long long temp[col];
        long long ans = 0;
        
        // 주어진 배열의 마지막 행(마지막 줄) 값을 temp로 가져온다.
        for(i = 0; i < col; i++) {
            temp[i] = points[row - 1][i];
        }
        
        // 밑에서 윗줄부터 시작한다.
        for (i = row - 2; i >= 0; i--) {
            long long p1 = INT_MIN;
            long long p2 = p1;
            for (j = 0; j < col; j++) {
                p1 = max(p1, temp[j] + j); // temp 이전줄 값을 사용해 더한다.
                temp[j] = p1 - j;
            }
            for (j = col - 1; j >= 0; j--){
                p2 = max(p2, temp[j] - j);
                temp[j] = max(temp[j], p2 + j);
                temp[j] += points[i][j];
            }
        }
        
        for (i = 0; i < col; i++) {
            ans = max(ans, temp[i]);
        }
        
        return ans;
    }
};