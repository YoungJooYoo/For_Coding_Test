class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        //unordered_map<string, multiset<string>> m; // ok if expect order within a group
        unordered_map<string, vector<string>> m;
        for (auto& a : strings) {
            string k = "";
            for (char c : a)  k += (c + 26 - a[0]) % 26+'a'; // encoded with lower  case letters: ensure a[0] is mapped to be 'a'; "+ 26" means to avoid to handle negative number
            m[k].push_back(a);            
        }
        for(auto& [k, v]: m) res.emplace_back(v);
        return res;
    }
};