class Solution {
public:
    int addDigits(int num) 
    {
        while(num > 9) {
            num = num / 10 + num % 10;
            printf("%d = %d + %d\n", num, num / 10, num % 10);
        }
        
        return num;
    }
};

/*

풀이법 :
문제의 본질은 반환은 무조건 0 ~ 9사이이다.
num % 9로 정리할 수 있다.

*/
