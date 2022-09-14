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
                while (head != NULL && j < m && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                i++;
                j--;
            }
            if (i < n)
            {
                while (head != NULL && i < n && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }
            if (j >= 0)
            {
                while (head != NULL && j >= 0 && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                j++;
                i--;
            }
            if (i >= 0)
            {
                while (head != NULL && i >= 0 && result[i][j] == -1)
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
		// Rest values are itself -1.
        return result;
    }
};