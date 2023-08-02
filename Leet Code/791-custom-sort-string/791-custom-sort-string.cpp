class Solution {
public:
    string customSortString(string order, string str) 
    {
        unordered_map<char, int> mp;
        string s = "";
        
        // 문자열 s로부터 해시테이블에 알파벳 빈도수 체크
        for (const auto& ch : str) {
            mp[ch]++;
        }
        
        // 문자열 order로부터 순서에 맞게 str로 부터 같은 문자를 찾는다.
        for (const auto& ch : order) {
            if (mp.find(ch) != mp.end()) { // 저장해둔 해시테이블에서 같은 문자가 있는지 검색
                auto it = mp.find(ch);
                while (it->second > 0) { // 문자 출연 빈도수에 맞춰 문자열에 누적한다.
                    s += it->first; // 
                    it->second -= 1;
                }
                mp.erase(it);
            }
        }
        
        // 순서에 맞게 문자열을 넣었다면, 남아있는 다른 문자열을 뒤에 붙이는 작업
        for (auto& it : mp) {
            while (it.second > 0) {
                s += it.first;
                it.second--;
            }
        }
        
        return s;
    }
};