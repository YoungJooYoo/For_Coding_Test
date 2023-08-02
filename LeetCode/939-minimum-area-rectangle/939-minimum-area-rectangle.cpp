class Solution {
public:
    int minAreaRect(vector<vector<int>>& points)
    {
        int result = INT_MAX;
        unordered_map<int, unordered_set<int>> x_axis_m;
        
        for (const auto& point : points) {
            x_axis_m[point[0]].insert(point[1]);
        }        
        
        for (size_t i = 0; i < points.size() - 1; i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                const auto& A = points[i];
                const auto& B = points[j];
                
                // Skip the point if they are on same x-axis or y-axis
                if (A[0] == B[0] || A[1] == B[1])
                    continue;
                
                // we look only for a diagonal point, and then assess it to see if it forms a rectangle,
                // by checking for existence of other 2 points that can form a rectangle.
                if (x_axis_m[A[0]].count(B[1]) == 1 && x_axis_m[B[0]].count(A[1]) == 1) {
                    int area = abs(A[0]-B[0]) * abs(A[1]-B[1]);
                    result = min (result, area);
                }
            }
        }
        
        return (result == INT_MAX) ? 0 : result;
    }
};