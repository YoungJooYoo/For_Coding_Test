class Solution {
public:
	//main function
    int countBattleships(vector<vector<char>>& board) 
    {
        int answer = 0;
        size_t m = board.size(); //  행의 길이
        size_t n = board[0].size(); // 열의 길이
		
        for (size_t i = 0 ; i < m ; i++){
            for (size_t j = 0 ; j < n ; j++){
                if (i == 0 and j == 0) {
                    if (board[i][j] == 'X') {
                        answer++;
                    }
                } else {
                    if (i > 0 and board[i-1][j] == 'X') {
                        continue;
                    }
                    else if (j > 0 and board[i][j-1] == 'X') {
                        continue;
                    }
                    else if (board[i][j] == '.') {
                        continue;
                    }
                    answer++;
                }
            }
        }
	
        return answer;
    }
};