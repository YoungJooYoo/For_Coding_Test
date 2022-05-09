class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq; // 알파벳별 빈도수
        priority_queue<pair<int, char>> q; //  빈도수 - 알파벳 묶음
        pair<int, char> curr; // 우선순위 큐에 넣은 pair
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