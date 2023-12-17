class Solution {
public:
    int val(int x, int y, vector<vector<int>>&img)
    {
        if (x < 0 || y < 0 || x >= img.size() || y >= img[0].size()) {
            return UNAVAILABLE;
        }

        return img[x][y];
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        const size_t ROW = img.size();
        const size_t COL = img[0].size();
        vector<vector<int>> ans(ROW, vector<int>(COL));
        
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                int sum = 0;
                int num_count = 0; // smopother를 위해 카운팅된 숫자들
                for (int k= -1; k <= 1; ++k) { // 행으로 3칸씩 탐색
                    for (int l =- 1; l <= 1; ++l) { // 열로 3칸씩 탐색
                        ++num_count; 
                        int temp = val(i - k, j - l, img);
                        if (temp == UNAVAILABLE) --num_count;
                        else sum += temp;
                    }
                }
                ans[i][j] = sum / num_count;
            }
        }

        return ans;
    }

private:
    enum { UNAVAILABLE = -1 };
};
/*
배열을 돌면서 순회하는 배열 숫자 기준으로  위아래양옆을 순환하면서, sum을 구하고, 유요한 범위의 숫자들을 카운팅해서
평균을 내서 다시 저장하면서 문제를 풀어나간다.
*/

// https://leetcode.com/problems/image-smoother/description/
