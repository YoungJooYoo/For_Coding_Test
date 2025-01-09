class TicTacToe 
{
public:
    TicTacToe(const int n)
        : mBoardSize(static_cast<size_t>(n)),
          mGameBoard(mBoardSize, vector<int>(mBoardSize, EMPTY_SPACE))
    {
        assert(MIN_BOARD_SIZE <= mBoardSize && mBoardSize <= MAX_BOARD_SIZE);
    }

    int move(const int row, const int col, const int player)
    {
        assert(player == 1 || player == 2);
        assert(0 <= row && row < mBoardSize);
        assert(0 <= col && col < mBoardSize);

        if (mGameBoard[row][col] == EMPTY_SPACE)
        {
            mGameBoard[row][col] = player;

            if (isTicTacToe(row, col, player) == true)
            {
                return player;
            }
        }

        return NO_WINNER;
    }

private:
    bool isTicTacToe(const int row, const int col, const int player) const
    {
        // Check row
        bool winRow = true;
        for (size_t j = 0; j < mBoardSize; ++j)
        {
            if (mGameBoard[row][j] != player)
            {
                winRow = false;
                break;
            }
        }
        if (winRow == true) return true;

        // Check column
        bool winCol = true;
        for (size_t i = 0; i < mBoardSize; ++i)
        {
            if (mGameBoard[i][col] != player)
            {
                winCol = false;
                break;
            }
        }
        if (winCol == true) return true;

        // Check left diagonal
        if (row == col)
        {
            bool winDiagLeft = true;
            for (size_t i = 0; i < mBoardSize; ++i)
            {
                if (mGameBoard[i][i] != player)
                {
                    winDiagLeft = false;
                    break;
                }
            }
            if (winDiagLeft == true) return true;
        }

        // Check right diagonal
        if (row + col == mBoardSize - 1)
        {
            bool winDiagRight = true;
            for (size_t i = 0; i < mBoardSize; ++i)
            {
                if (mGameBoard[i][mBoardSize - i - 1] != player)
                {
                    winDiagRight = false;
                    break;
                }
            }
            if (winDiagRight == true) return true;
        }

        return false;
    }

private:
    const size_t mBoardSize;
    vector<vector<int>> mGameBoard;

    enum
    {
        MIN_BOARD_SIZE = 2,
        MAX_BOARD_SIZE = 100,

        NO_WINNER = 0,
        EMPTY_SPACE = -1,
    };
};

// https://leetcode.com/problems/design-tic-tac-toe/description/
