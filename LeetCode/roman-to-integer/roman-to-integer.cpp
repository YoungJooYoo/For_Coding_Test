class Solution {
public:
    int romanToInt(string s) {
        // 스트링 하나씩 읽는다.
        int result = 0;
        std::map<char, int> roman_number;
        
        // Map key-value 심볼과 값 초기화
        roman_number['I'] = 1;
        roman_number['V'] = 5;
        roman_number['X'] = 10;
        roman_number['L'] = 50;
        roman_number['C'] = 100;
        roman_number['D'] = 500;
        roman_number['M'] = 1000;
       
        // 입력조건에 맞지 않는 문자열 길이나 NULL 오면 종료             
        if (s.length() == 0 || s.length() < 1 || s.length() > 15) {
            return 0;
        }
        
        // 맵 키 밸류 사용법
        for (size_t i = 0; i < s.length(); ++i) {
                if(s[i] == 'I' && (i+1) < s.length() && s[i+1] == 'V') {
                result += 4;
                ++i; // 2칸 넘어가기
                }
                else if(s[i] == 'I' && (i+1) < s.length() && s[i+1] == 'X') {
                    result += 9;
                    ++i;
                }
                else if(s[i] == 'X' && (i+1) < s.length() && s[i+1] == 'L') {
                    result += 40;
                    ++i;
                }
                else if(s[i] == 'X' && (i+1) < s.length() && s[i+1] == 'C') {
                    result += 90;
                    ++i;
                }
                else if(s[i] == 'C' && (i+1) < s.length() && s[i+1] == 'D') {
                    result += 400;
                    ++i;
                }
                else if(s[i] == 'C' && (i+1) < s.length() && s[i+1] == 'M') {
                    result += 900;
                    ++i;
                }
                else {
                    result = result + roman_number[s[i]];
                }
        }
        
        return result;
    }
};