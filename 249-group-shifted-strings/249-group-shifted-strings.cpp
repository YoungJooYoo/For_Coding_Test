class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for (const auto& str : strings) {
            string k = "";
            for (const char& c : str)  {
                k += (c + 26 - str[0]) % 26 + 'a'; // encoded with lower  case letters: ensure a[0] is mapped to be 'a'; "+ 26" means to avoid to handle negative number
            }
            m[k].push_back(str);            
        }
        
        for (const auto& [key, value] : m) { 
            res.emplace_back(value);
        }
        
        return res;
    }
};