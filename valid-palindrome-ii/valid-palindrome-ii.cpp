class Solution {
public:
    bool validPalindrome(string s) {
        const size_t str_length = s.size();
        int begin = 0;
        int end = str_length - 1;
        
        while(begin < end) {
            if (s[begin] != s[end]) {
                return isPalin(s, begin + 1, end) || isPalin(s, begin, end - 1); // 문자가 하나만 틀리면, 그 구간 뛰어넘고 다시 비교하면 true가 나오고, 또 틀린 구간이 있으면 false 한번만 틀린건지 확인하는 구문
            }
            begin++;
            end--;
        }
        
        return true;
    }
    
    // 인덱스 오른쪽 왼쪽 문자열이 같은지 확인
    bool isPalin(string s, int left, int right) {
	    while (left < right) {
		    if (s[left] != s[right]) {
                return false;
            }
		    left++;
		    right--;
	    }
        
	    return true;
    }
};