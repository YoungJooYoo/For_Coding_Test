class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        int i;
        int j;
        int row = points.size();
        int col = points[0].size();
        long long temp[col];
        
        for(i = 0; i< col; i++) {
            temp[i] = points[row - 1][i];
        }
            
        long long ans = 0;
        
        for (i = row - 2; i >= 0; i--) {
            long long p1 = INT_MIN;
            long long p2 = p1;
            for (j = 0; j < col; j++) {
                p1 = max(p1, temp[j] + j);
                temp[j] = p1 - j;
            }
            for(j = col - 1; j >= 0; j--){
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