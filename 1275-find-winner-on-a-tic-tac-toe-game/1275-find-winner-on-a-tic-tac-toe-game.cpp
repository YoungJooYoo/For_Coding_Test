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

            board[row][col] = player; // Mark the current move with the current playrer's id.

            if (checkRow(row, player) || checkCol(col, player) || 
                (row == col && checkDiagonal(player)) ||
                (row + col == ARRAY_SIZE - 1 && checkAntiDiagonal(player))) {
                return player == 1 ? "A" : "B";
                //return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
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
*/