class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        set<int> set(arr.begin(), arr.end());
        unordered_map<int, int> mp; // index, value;
        int rank = 1;
        
        for (const auto& num : set) {
            mp[num] = rank++;
        }
        
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        
        return arr;
    }
};