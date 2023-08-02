class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        for (size_t i = 0; i < s.size(); i++) {
            mp[s[i]] = i; // 해시에 문자의 인덱스를 넣는다.
        }
        
        for (size_t i = 0; i < s.size(); i++) {
            max_index = max(max_index, mp[s[i]]);
            if (max_index == i) {
                res.push_back(max_index - prev); // partition time
                prev = max_index;
            }
        }
        
        return res;
    }
    
private:
    unordered_map<char, int> mp;
    vector<int> res;
    int prev = -1;
    int max_index = 0;
};