class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size() - 1; // 예시) 배열 인덱스  0 ~ 9 = 10개 index는 10 - 1
        int count = 0; 
        
        // 문자열 속 마지막 문자열 뒤에 있는 공백 카운트하기
        // ABCD(공백)(공백)(null : 문자열 끝)
        // index를 공백공백 건너 띄어서 ABCD까지 인덱스가 D까지 오게 만든다.
        while (s[length] == ' ') {
            length--;
        }
        
        // 공백없는 인덱스부터 다음 공백나오기 전까지 문자열 요소를 count
        while (length >= 0 && s[length] != ' ') {
            count++;
            length--;
        }
        return count ; 
    }
};