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
        
    bool checkDiagonal(int player) 
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

            // If any of the winning conditions is met, return the current player's id.
            if (checkRow(row, player) || checkCol(col, player) || 
                (row == col && checkDiagonal(player)) ||
                (row + col == ARRAY_SIZE - 1 && checkAntiDiagonal(player))) {
                return player == 1 ? "A" : "B";
                return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }

        // If all moves are completed and there is still no result, we shall check if 
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == 3 * 3 ? "Draw" : "Pending";
    }
    
};   