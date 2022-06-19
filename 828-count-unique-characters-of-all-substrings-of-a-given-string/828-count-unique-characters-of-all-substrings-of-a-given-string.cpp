class Solution 
{
public:
    int uniqueLetterString(string& s) 
    {
        int ans = 0;
        
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int cnt = 0;
            int curr = 0;
            int prev = 0;
            
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ch) {
                    cnt++; // 알파벳의 빈도수 증가
                    prev = curr; // 이전 인덱스 기억
                    curr = i; // 현재 인덱스 갱신
                }
                if (cnt == 1) { // 유니크한 경우
                    ans += curr + 1;
                } 
                else {
                    ans += curr - prev;
                }
            }
        }
        
        return ans;
    }
};