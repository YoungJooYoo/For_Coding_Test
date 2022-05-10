class Solution {
public:
    int myAtoi(string s) 
    {
        int res = 0;
        int sign = 1;
		size_t i = 0;
        
        // 공백문자 건너 띄기
        while (i < s.size() && s[i] == ' ') {
            i++;
        }  
        
        // 음수 체크
        if(s[i]=='-' || s[i]=='+') {      
            sign = s[i] =='-'?-1:1;
            i++;
        }
        
        
        
        // now iterate across digits if any
		// should only be in range 0-9
        while (i < s.length() && (s[i] >= '0' && s[i] <= '9')) { //traverse string till nondigit not found or string ends
            int digit = (s[i] - '0') * sign;
            if (sign == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10))) {
                return INT_MAX; 
            } //check for overflow
            if (sign == -1 && (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < INT_MIN % 10))) {
                return INT_MIN; //check for underflow
            }
            res = res * 10 + digit; // update res
            i++;
        }
    
        return res;
    }
};