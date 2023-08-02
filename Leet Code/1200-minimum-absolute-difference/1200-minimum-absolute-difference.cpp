class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        vector<vector<int>> result;
        vector<int> temp(2, 0);
        
        sort(arr.begin(), arr.end());
        int min_value = INT_MAX;
        
        for (size_t i = 0; i < arr.size() - 1; i++) {
            min_value = min(min_value, arr[i + 1] - arr[i]);
        }
        
        for (size_t i = 0; i < arr.size() - 1; i++) {
            temp[0] = arr[i];
            temp[1] = arr[i + 1];
            if (arr[i + 1] - arr[i] == min_value) {
                result.push_back(temp);
            }
        }
        
        return result;
    }
};