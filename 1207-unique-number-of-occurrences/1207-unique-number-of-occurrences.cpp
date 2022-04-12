class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, int> mp;
        unordered_set<int> set;
        
        for (const int& elem : arr) {
            mp[elem]++;
        }   
        for (const auto elem : mp) { // 중복이 없다면 set size와 mp 사이즈가 같아야한다.
            set.insert(elem.second); 
        }
        
        return set.size() == mp.size() ? true : false;
    }
};