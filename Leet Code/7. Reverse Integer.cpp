#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)

class Solution {
public:
    int reverse(int x) {
        
        long long result = 0; // result 계산 중 int 범위 넘어갈 수 있다.
        int flag = 0;
        
        // 입력값 경계점 범위체크
        if (x <= INT_MIN || x >= INT_MAX) {
            return 0;
        }
        // 입력 값 x가 음수라면
        if(x < 0) {
            flag = 1;
            x = x * (-1); // 일단 양수로 만들어주고 마지막에 음수로 만든다.
        }
            
        while (x >= 10) // 10보다 클때까지 해야지 1의 자리까지 x값 계산완료
        {
            result = result + (x % 10); // 입력받은 x의 맨 앞자리부터 뒤로 보내기
            result = result * 10; //1의자리부터 10의자리 100의 자리로 증가
            x = x / 10; // 입력받은 숫자 x의 맨 앞자리부터 제거
        }
        result += x; // result의 마지막 1의자리 계산 됫 것 더해주면 완료
        
       if(flag == 1) {
           result = result * -1; // 입력 값 x가 음수면 양수 전환 후 계산 끝나면 다시 음수로 만드낟.
       }

        if(result<= INT_MIN || result >=  INT_MAX) {
            return 0;
        }
            
        return result;
    }
};