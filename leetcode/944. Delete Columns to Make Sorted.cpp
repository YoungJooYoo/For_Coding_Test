class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int delete_count = 0;
        const int row = strs.size();
        const int col = strs[0].size();
        
        for(int j = 0; j < col; j++) {
            for(int i = 0; i < row - 1; i++) {
                if(strs[i][j] > strs[i + 1][j]) {
                    delete_count++;
                    break;
                }
            }
        }

        return delete_count;
    }
};

// https://leetcode.com/problems/delete-columns-to-make-sorted/description/
