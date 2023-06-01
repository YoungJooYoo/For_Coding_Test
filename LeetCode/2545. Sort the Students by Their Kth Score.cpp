class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        const size_t row = score.size();
        const size_t col = score[0].size();
        vector<int> sorted_k;
        vector<vector<int>> result;

        for (size_t i = 0; i < row; ++i) {
            sorted_k.push_back(score[i][k]);
        }

        sort(sorted_k.begin(), sorted_k.end(), greater<int>()); // 오름차순 정렬
        
        // 정렬된k배열과 일치하는 행 복사하기
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < row; ++j) {
                vector<int> temp;
                if (sorted_k[i] == score[j][k]) {
                    for (size_t k = 0; k < col; ++k) {
                        temp.push_back(score[j][k]);
                    }
                    result.push_back(temp);
                }
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/
