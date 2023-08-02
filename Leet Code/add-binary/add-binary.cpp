class Solution {
private:
    int toInt(char c) {
        return (int) (c - '0');
    }

    char toChar(int i) {
        return (char) (i + '0');
    }
    
public:
    string addBinary(string a, string b) {
        string ans;
        size_t carry = 0;
        size_t sum = 0; // 각 자리수의 합
        size_t val1; // 문자열에서 가져오는 피연산자
        size_t val2; // 문자열에서 가져오는 피연산자
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while(i >= 0 || j >= 0 || carry != 0) {
            val1 = i >= 0 ? toInt(a[i--]): 0; // 문자열a 뒷자리부터 숫자 추출
            val2 = j >= 0 ? toInt(b[j--]): 0; // 문자열b 뒷자리부터 숫자 추출
            sum = val1 + val2 + carry; 
            carry = sum / 2; // carry는 0과 1만 나오게 조정
            ans = ans + toChar(sum % 2); // 계산된 숫자 누적해서 붙이기
        }
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};
    
    


