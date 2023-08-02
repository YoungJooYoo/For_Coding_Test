class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        unordered_map<int, int> mp;
        vector<int> result;
        
        for (const int& num : arr1) {
            mp[num]++;
        }
        for (const int& num : arr2) {
            mp[num]++;
        }
        for (const int& num : arr3) {
            mp[num]++;
            if (mp[num] == 3) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};