class Solution 
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, const ListNode* head) 
    {
        vector<vector<int>> result(m, vector<int>(n, INIT));
        const ListNode* curr = head;
        int top = 0; 
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        int dir = 0;  // 0: right, 1: down, 2: left, 3: up

        while (curr != nullptr) 
        {
            if (dir == RIGHT) 
            {
                for (int j = left; j <= right && curr != nullptr; ++j) 
                {
                    result[top][j] = curr->val;
                    curr = curr->next;
                }
                ++top;
            } 
            else if (dir == DOWN) 
            {
                for (int i = top; i <= bottom && curr != nullptr; ++i) 
                {
                    result[i][right] = curr->val;
                    curr = curr->next;
                }
                right--;
            } 
            else if (dir == LEFT) 
            {
                for (int j = right; j >= left && curr != nullptr; --j) 
                {
                    result[bottom][j] = curr->val;
                    curr = curr->next;
                }
                bottom--;
            } 
            else if (dir == UP) 
            { 
                for (int i = bottom; i >= top && curr != nullptr; --i) 
                {
                    result[i][left] = curr->val;
                    curr = curr->next;
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }

        return result;
    }

private:
    enum
    {
        INIT = -1,
        RIGHT = 0, 
        DOWN = 1, 
        LEFT = 2, 
        UP = 3
    };
};

// https://leetcode.com/problems/spiral-matrix-iv/
