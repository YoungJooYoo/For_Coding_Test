class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, int> mp;
        unordered_set<int> set;
        
        for (const int& elem : arr) {
            mp[elem]++;
        }   
        for (const auto elem : mp) {
            set.insert(elem.second); 
        }
        
        return set.size() == mp.size() ? true : false;
    }
};