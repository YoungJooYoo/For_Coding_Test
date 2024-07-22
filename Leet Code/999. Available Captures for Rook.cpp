class Solution 
{
public:
    int numRookCaptures(const vector<vector<char>>& board) 
    {
        int result = 0;
        int i;
        int j;

        GetRookPosition(i, j, board);

        // 동
        for (int idx = j + 1; idx < BOARD_SIZE; ++idx)
        {
            if (board[i][idx] == 'B') break;
            if (board[i][idx] == 'p') 
            {
                ++result;
                break;
            }
        }

        // 서
        for (int idx = j - 1; idx >= 0; --idx)
        {
            if (board[i][idx] == 'B') break;
            if (board[i][idx] == 'p') 
            {
                ++result;
                break;
            }
        }

        // 남
        for (int idx = i + 1; idx < BOARD_SIZE; ++idx)
        {
            if (board[idx][j] == 'B') break;
            if (board[idx][j] == 'p') 
            {
                ++result;
                break;
            }
        }

        // 북
        for (int idx = i - 1; idx >= 0; --idx)
        {
            if (board[idx][j] == 'B') break;
            if (board[idx][j] == 'p') 
            {
                ++result;
                break;
            }
        }

        return result;        
    }

    void GetRookPosition(int& idx, int& jdx, const vector<vector<char>>& board)
    {
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            for (int j = 0; j < BOARD_SIZE; ++j)
            {
                if (board[i][j] == 'R')
                {
                    idx = i;
                    jdx = j;
                    return;
                }
            }
        }
    }

private:
    enum { BOARD_SIZE = 8 };
};

// https://leetcode.com/problems/available-captures-for-rook/description/

/*

문제 999. 룩의 가능한 캡처 수

난이도: 쉬움

주제: 체스

다음은 8 x 8 크기의 체스판을 나타내는 행렬입니다. 정확히 하나의 흰색 룩('R')이 있고, 몇 개의 흰색 비숍('B')과 몇 개의 검은색 폰('p')이 있습니다. 빈 칸은 '.'으로 표시됩니다.

룩은 가로 또는 세로로 (위, 아래, 왼쪽, 오른쪽) 다른 말이나 체스판의 가장자리에 도달할 때까지 여러 칸을 이동할 수 있습니다. 룩이 한 번의 이동으로 폰이 있는 칸으로 이동할 수 있다면, 그 폰을 공격하고 있다고 할 수 있습니다.

주의: 룩은 비숍이나 폰과 같은 다른 말을 통과하여 이동할 수 없습니다. 즉, 룩은 경로에 다른 말이 있는 경우 폰을 공격할 수 없습니다.

흰색 룩이 공격하는 폰의 수를 반환하세요.
*/
