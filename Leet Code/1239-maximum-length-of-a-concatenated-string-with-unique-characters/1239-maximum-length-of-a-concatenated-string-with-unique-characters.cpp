class Solution {
public:
    bool is_unique(string& str) {
        int n = str.size();
        vector<int> mp(26, 0); // mp will store the count of all the characters in string
        
        for (int i = 0; i < n; i++) {
            mp[str[i] - 'a']++;
            if (mp[str[i] - 'a'] > 1) return false; // if we found duplicates return false
        }
        
        return true;
    }
    
    void helper(vector<string>& arr, int i, const size_t ARR_SIZE, string curr_str)
    {
        if (is_unique(curr_str) == false) return; // if we have got duplicate int our result then simply return
        
        if (i == ARR_SIZE) { // 재귀 종료조건
            int curr_str_size = curr_str.size();
            if (curr_str_size > maxi) {
                maxi = max(maxi, curr_str_size); // update maxi
            }
            
            return;
        }
        
        helper(arr, i + 1, ARR_SIZE, curr_str + arr[i]); // we have two options either include the curr string or exclude  // include the curr string
        helper(arr, i + 1, ARR_SIZE, curr_str); // exclude the curr string
    }
    
    int maxLength(vector<string>& arr) 
    {
        helper(arr, 0, arr.size(), "");
        
        return maxi;
    }
    
private:
    int maxi = 0; // function for checking uniqueness of the string
};