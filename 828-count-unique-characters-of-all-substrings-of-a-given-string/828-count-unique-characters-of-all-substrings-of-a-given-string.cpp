class Solution 
{
public:
    int uniqueLetterString(string& s) 
    {
        int ans = 0;
        
        for (char ch = 'A'; ch <= 'Z'; ch++) { // 알파벳 순서대로 검출하기
            int cnt = 0;
            int curr = 0; // init  부분 문자열 길이의 전체 합
            int prev = 0; // init  이전 부분 문자열  전체 합
            
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ch) {
                    cnt++; // 알파벳의 빈도수 증가
                    prev = curr; // prev 갱신
                    curr = i; // 갱신
                }
                if (cnt == 1) { // 유니크한 경우
                    ans += curr + 1; // 인덱스 + 1 = 길이
                } 
                else { // cnt != 1 아닌 경우 빼기. 유니크하지 않아, 이전에 더한 것 빼버리기
                    ans += curr - prev;
                }
            }
        }
        
        return ans;
    }
};