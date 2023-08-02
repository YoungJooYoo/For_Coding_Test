class Solution {
public:
    bool helper(string s, string t) 
    {
        unordered_map<char, char> mp;
        
        for (size_t i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {  // s[i]가 이미 존재한다면,
                if (mp[s[i]] != t[i]) { // 해당 문자가 존재하는 상태에서 t문자여르이 문자와 일치 하지 않으면 반환
                    return false;
                }
            }
            else {
                mp[s[i]] = t[i];
            }
        }
        
        return true;
    }
    
    bool isIsomorphic(string s, string t) 
    {
        return (helper(s, t) && helper(t, s)) ? true : false;
    }
};

/*
풀이법 :
해시맵을 이용해 저장
find 함수를 이용해 순서를 확인한다.
*/