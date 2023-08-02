class Solution 
{
public:
    int minPartitions(string n) 
    {
        int result = 0;
        
        for (const char& i : n) {
            result = max(result, i - '0');
        }
        
        return result;
    }
};

/*

풀이법 :
input 문자열에서, 각 자리수 중에서 가장 큰 값을 구하면 된다
ex) 123456789 -> 9가 최대값

*/