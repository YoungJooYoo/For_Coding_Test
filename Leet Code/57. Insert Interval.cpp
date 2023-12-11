class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result;
        int new_x = newInterval[0];
        int new_y = newInterval[1];

        // First, determine the acceptable range for newInterval.
        for (const auto& interval : intervals) {
            const int x = interval[0];
            const int y = interval[1];
            if (x <= new_x && new_x <= y) new_x = x;
            if (x <= new_y && new_y <= y) new_y = y;
        }
        result.push_back({new_x, new_y}); // insert the range of the newly obtained newInterval into the vector.

        // Exclude the arrays that fit within newInterval and put the rest into the result array.
        for (const auto& interval : intervals) {
            const int x = interval[0];
            const int y = interval[1];
            if(x > new_x && y > new_y) result.push_back(interval);
            else if(x < new_x && y < new_y) result.push_back(interval);;
        }
        sort(result.begin(), result.end()); // Since the new range of newInterval is placed at the beginning, sort the result array.
        
        return result;
    }
};

// https://leetcode.com/problems/insert-interval/description/
