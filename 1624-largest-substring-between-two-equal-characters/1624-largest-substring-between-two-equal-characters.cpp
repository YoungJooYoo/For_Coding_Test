class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        unordered_map<char, int> mp; // 문자-인덱스 매핑
        int ans = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (mp.count(s[i])) { // 해당 문자의 인덱스가 존재하면,
                ans = max(ans, i - mp[s[i]] - 1);
            }
            else {
                mp[s[i]] = i; // 해당 문자의 인덱스를 저장
            }
        }
        
        return ans;
    }
};