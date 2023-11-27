// Solution 1
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        vector<int> result;

        for (const vector<int>& i : nums) {
            for (int j = i[0]; j <= i[1]; ++j) {
                if (find(result.begin(), result.end(), j) == result.end()) {
                    result.push_back(j);
                }
            }
        }

        return result.size();
    }
};



// Solution 2
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        set<int> result;

        for (const vector<int>& i : nums) {
            for (int j = i[0]; j <= i[1]; ++j) {
                if (find(result.begin(), result.end(), j) == result.end()) {
                    result.insert(j);
                }
            }
        }
        
        return result.size();
    }
};

// https://leetcode.com/problems/points-that-intersect-with-cars/description/
