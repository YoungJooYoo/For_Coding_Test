class Solution {
private:
    const size_t ARRAY_SIZE = 3;
    vector<vector<int>> board;
    
    // Check if any of 4 winning conditions to see if the current player has won.
    bool checkRow(int row, int player) 
    {
        for (size_t col = 0; col < ARRAY_SIZE; ++col) {
            if (board[row][col] != player) {
                return false;
            }
        }
        return true;
    }
    
    bool checkCol(int col, int player) 
    {
        for (size_t row = 0; row < ARRAY_SIZE; ++row) {
            if (board[row][col] != player) {
                return false;
            }
        }
        return true;
    }
        
    bool checkDiagonal(int player) // 대각선체크
    {
        for (size_t row = 0; row < ARRAY_SIZE; ++row) {
            if (board[row][row] != player) {
                return false;
            }
        }
        return true;
    }
        
    bool checkAntiDiagonal(int player) 
    {
        for (size_t row = 0; row < ARRAY_SIZE; ++row) {
            if (board[row][ARRAY_SIZE - 1 - row] != player) {
                return false;
            }
        }
        return true;
    }

public:
    string tictactoe(vector<vector<int>>& moves) 
    {        
        board.assign(ARRAY_SIZE, vector<int>(ARRAY_SIZE, 0));
        int player = 1;

        for (const vector<int>& move : moves) {
            size_t row = move[0];
            size_t col = move[1];

            board[row][col] = player;

            if (checkRow(row, player) || checkCol(col, player) || 
                (row == col && checkDiagonal(player)) ||
                (row + col == ARRAY_SIZE - 1 && checkAntiDiagonal(player))) {
                return player == 1 ? "A" : "B";
            }

            player *= -1;
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};   

/*
풀이법 :

배열의 순서가 A, B, A, B 순서로 나아간다.
따라서 Player를 flag로 두고 1 = a, -1 = b로 둔다.

주어진 함수에 따라 승자인지 판단을 한다.
1. 현재 위치에서 row 전체가 mark 되었는지.
2. 현재 위치에서 col 전체가 mark 되었는지
3. 현재 위치에서 대각선(역슬래시 방향)에서 mark가 되었는지
4. 현재 위치에서 대각선(슬래시 방향 : /)에서 mark가 되었는지

4가지 승리 조건을 판단 후, 일치하면 A or B를 반환한다.
없는 경우 플레이어 A, B를 바꾸면서 반복문을 다시 실행

이 반복문을 통해 승리 판별을 다해보았으나, 결과가 없는 경우
보드의 모든 칸에 채워졌다면 무승부를 반환, 아니라면 Pending 반환
*/