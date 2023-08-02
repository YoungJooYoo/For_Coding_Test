class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        unordered_map<char, int> mp; // 문자-인덱스 매핑
        int ans = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (mp.count(s[i])) { // 해당 문자의 인덱스가 존재하면,
                ans = max(ans, i - mp[s[i]] - 1); // 이전 길이와, 현재 인덱스에서 반환할 문자열 길이 중 긴 것 선택.
            }
            else {
                mp[s[i]] = i; // 해당 문자의 인덱스를 저장
            }
        }
        
        return ans;
    }
};

/*

풀이법 :
중복 되는 두 문자열의 사이의 길이를 구하는 것
즉, 시작점과 끝점을 제외한 그 사이 문자열의 길이를 구한다.
중복된 문자의 시작과 끝 인덱스를 기억하는 것이 중요

*/