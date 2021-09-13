class Solution {
public:
    bool isPalindrome(int x) { // 아이디어, 음수 거르고 양수 뒤집어서 같으면 True
        
        long long reverse_result = 0;
        int answer = x;
        
        if(x < 0) {
            return false;
        }
        
        // 숫자 뒤집기
        while (x >= 10) {
            reverse_result = reverse_result + (x % 10);
            reverse_result = reverse_result * 10;
            x = x / 10;
        }
        reverse_result = reverse_result + x;
        
        if (reverse_result == answer) {
            return true;
        }
        
        return false;
    }
};
