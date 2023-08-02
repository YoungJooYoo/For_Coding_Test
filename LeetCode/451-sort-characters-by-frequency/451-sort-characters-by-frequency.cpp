class Solution {
public:
    string frequencySort(string s) 
    {
        map<char, int> freq; // 알파벳별 빈도수
        priority_queue<pair<int, char>> q; //  빈도수 - 알파벳 묶음
        pair<int, char> curr; // 우선순위 큐에 넣은 pair
        string res;
        
        // 단어의 빈도수 체크
        for (const char& ch : s) {
             freq[ch]++;
        }
        
        // 우선순위 큐에 빈도수와 알파벳 pair 형태로 로 넣기, 빈도수로 정렬한다.
        for (const auto& [ch, frq] : freq) {
            q.push({frq, ch});
        }
        
        while (!q.empty()) {
            curr = q.top();
            q.pop();
            res += string(curr.first, curr.second);
        }
        
        return res;
    }
};