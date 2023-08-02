class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
    {
        vector<vector<int>> result(n, vector<int>(m, -1));
        int i = 0;
        int j = 0;

        while (head != NULL)
        {
            if (j < m)
            {
                while (head != NULL && j < m && result[i][j] == -1) // -> 방향으로 진행
                {
                    result[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                i++; // 세로 한칸 내려주기
                j--; // 세로방향 길이 1 줄이기
            }
            if (i < n)
            { 
                while (head != NULL && i < n && result[i][j] == -1) // ↓ 방향으로 진행
                {
                    result[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--; // 세로로 한칸 위 올려주기
                j--; // 가로 방향 길이 1 줄이기
            }
            if (j >= 0)
            {
                while (head != NULL && j >= 0 && result[i][j] == -1) // <- 방향으로 진행
                {
                    result[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                j++; 
                i--; // 한칸 업
            }
            if (i >= 0) 
            {
                while (head != NULL && i >= 0 && result[i][j] == -1) // 위로 가는 방향으로 진행
                {
                    result[i][j] = head->val;
                    head = head->next;
                    i--;
                }
                i++;
                j++;
            }
            
            n--;
            m++;
        }

        return result;
    }
};