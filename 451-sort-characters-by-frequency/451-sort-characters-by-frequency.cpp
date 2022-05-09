class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> q;
        pair<int, char> curr;
        string res;
        
        // 단어의 빈도수 체크
        for (const char& ch : s) {
             freq[ch]++;
        }
        
        for (const auto& [a, frq] : freq) {
            q.push({frq, a});
        }
        
        
        while (!q.empty()) {
            curr = q.top();
            q.pop();
            res += string(curr.first, curr.second);
        }
        
        return res;
    }
};