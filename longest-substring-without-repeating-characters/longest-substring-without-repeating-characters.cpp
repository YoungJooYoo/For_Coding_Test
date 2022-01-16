class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dictionary(256, -1); // 아스키코드 0 ~ 256, -1 = 문자 나온적 없음
        int start = -1;
        int max_value = 0;
        
        for (int i = 0; i < s.length(); i++) {
            start = max(start, dictionary[s[i]]);  //
            dictionary[s[i]] = i; // 이 문자가 인덱스 어디에서 나왔는지 저장
            max_value = max(max_value, i - start); // i - start = length
        }
        
        return max_value;
    }
};