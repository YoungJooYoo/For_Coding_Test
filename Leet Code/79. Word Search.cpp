
class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, string& word, int idx) 
    {
        if (idx >= l) {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) { // 범위체크, 행렬에서 탐색하면서 word랑 일치하는지 인덱스별로 비교
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$'; // 방문표시
        
        for (const auto& dir : directions) { // 동서남북 전부 탐색
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if (find(board, i_, j_, word, idx + 1) == true) {
                return true;
            }
        }
        
        board[i][j] = temp; // 방문표시 복구
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size();
        n = board[0].size();
        l = word.length();

        if (m * n < l) {
            return false;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, word, 0) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int l;
    int m;
    int n;
};

// https://leetcode.com/problems/word-search/description/
