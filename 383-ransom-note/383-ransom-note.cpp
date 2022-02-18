class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> mp;
        
        // magazine 길이가 더 기므로 먼저 시작
        for (const char& c : magazine) {
            mp[c]++;
        }
        for (const char& c : ransomNote) {
            if (mp[c] == 0) { // 매거진이 쓰이지 않았다 == 0
                return false;
            }
            mp[c]--;
        }
    
        return true;
    }
};