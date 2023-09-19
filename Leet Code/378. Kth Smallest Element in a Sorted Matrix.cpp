class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int, vector<int>, std::greater<int>> q;

        for (const auto& row : matrix) {
            for (const auto& elem : row) {
                q.push(elem);
            }
        }

        int result = 0;
        while(k-- > 0) {
            result = q.top();
            q.pop();
        }

        return result;
    }
};

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
