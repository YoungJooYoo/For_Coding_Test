class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> result(n + 1, 0); // result[0]은 0으로 자동 초기화
        for (size_t i = 1; i <= n; i++) { // 1부터 시작해서 구한다.
            result[i] = result[i >> 1] + (i & 1); // i >> i 배열의 인덱스의 비트 연산을 통해 인덱스 절반을 구한다. i & 1 => 짝수면 0 홀수면 1이 나오게 한다.
        }
        return result;
    }
};

/*
풀이법 : 
0은 비트1 0개 켜짐
1은 비트가 1개 켜짐
2는 비트가 1개 켜짐
3은 비트가 2개켜짐
4는 비트가 1개 켜짐
5는 비트가 2개 켜짐
....
....
....
패턴을 구한다.
*/