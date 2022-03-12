class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> result(n, 0);
        int num = 1;
        
        if (n % 2 == 0) { // 길이가 짝수인 경우
            for (size_t i = 0; i < n / 2; i++) {
                result[i] = num + 1;
                num++;
            }
            num = 1;
            for (size_t i = (n / 2); i < n; i++) {
                result[i] = -(num + 1);
                num++;
            }
        }
        else { // 길이가 홀 수 인경우
            result[n / 2] = 0;
            for (size_t i = 0; i < n / 2; i++) {
                result[i] = num + 1;
                num++;
            }
            num = 1;
            for (size_t i = (n / 2) + 1; i < n; i++) {
                result[i] = -(num + 1);
                num++;
            }
        }
              
        return result;
    }
};

/*

풀이법:
 // n : 배열의 길이
        // 합이 0 : 
*/
