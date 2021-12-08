class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        const size_t row_length = image.size();
        const size_t col_length = image[0].size();
        
        // 배열의 좌우 값 반전하기
        for (size_t i = 0; i < row_length; i++) {
            size_t j = 0;
            size_t k = col_length - 1;
            while (j < k) {
                swap(image[i][j], image[i][k]);
                j++;
                k--;
            }
        }
        
        // 0 -> 1,  1 -> 0 반전하기
        for (size_t i = 0; i < row_length; i++) {
            for (size_t j = 0; j < col_length; j++) {
                if (image[i][j] == 0) {
                    image[i][j] = 1;
                }
                else {
                    image[i][j] = 0;
                }
            }
        }
        
        return image;
    }
};