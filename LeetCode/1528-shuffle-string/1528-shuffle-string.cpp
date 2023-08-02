class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        string ans = "";
        vector<pair<int, char>> arr;
        
        for (size_t i = 0; i < s.size(); i++) {
            arr.push_back(make_pair(indices[i], s[i]));    
        }
        
        sort(arr.begin(), arr.end());
        
        for (size_t i = 0; i < s.size(); i++) {
            ans = ans + arr[i].second;
        }
    
        return ans;                              
    }
};