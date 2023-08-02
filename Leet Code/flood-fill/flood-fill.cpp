class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        if (image[sr][sc] != new_color) {
            dfs(image, sr, sc, image[sr][sc], new_color);
        }

        return image;
    }  
    
private:
    void dfs(vector<vector<int>>& image, int i, int j, int curr_color, int new_color) {
        // 종료조건 배열의 범위를 나가는 경우, 현재 컬러와 뉴컬러가 같은 경우
        if(i < 0 || j < 0 ||  i >= image.size() || j >= image[0].size() || image[i][j] != curr_color) {
            return;
        }
            
        image[i][j] = new_color;

        // 4방향 동서남북으로 탐색
        dfs(image, i, j - 1, curr_color, new_color); // 서
        dfs(image, i, j + 1, curr_color, new_color); // 동
        dfs(image, i - 1, j, curr_color, new_color); // 북
        dfs(image, i + 1, j, curr_color, new_color); // 남
    }
};