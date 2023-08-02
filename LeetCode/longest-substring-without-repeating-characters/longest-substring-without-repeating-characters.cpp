class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dictionary(256, -1); // 아스키코드 0 ~ 256, -1 = 문자 나온적 없음
        int start = -1;
        int max_value = 0;
        
        for (int i = 0; i < s.length(); i++) {
            start = max(start, dictionary[s[i]]);  // 문자 사전 ex) 'a' = 97, 97번 인덱스가 start
            dictionary[s[i]] = i; // 이 문자가 인덱스 어디에서 나왔는지 저장, 97번('a')는 i번째에서 등장
            max_value = max(max_value, i - start); // i - start = length, 즉, 해당 문자 중복으로 나올때 체크
        }
        
        return max_value;
    }
};