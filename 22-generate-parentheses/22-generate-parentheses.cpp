class Solution {
public:
    void recursive(string curr, int open, int close) 
    {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        
        if (open > 0) {
            recursive(curr + "(", open - 1, close + 1); // opne 괄호를 추가하면  opne - 1하고, 닫아야하는 괄호 + 1
        } 
        if (close > 0) {
            recursive(curr + ")", open, close - 1); // close 괄호를 추가하면  opne + 1하고, 닫아야하는 괄호 - 1
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        recursive("", n, 0);
        return res;
    }
    
private:
    vector<string> res;
};

/*
풀이법 :
재귀에 가장 좋은 시각화 자료 :
https://youtu.be/s9fokUqJ76A?t=343

즉 시작은 ( 이 괄호 부터 가능하며, 이 괄화 갯수에 따라 호출되는 재귀 함수를 통해 문제를 푼다.

예시 1번을보면
output에

((( )))  -> open 괄호가 먼저 3개 나온 경우
(( )()), (( ))() -> open 괄호가 먼저 2개 나온 경우
( )(()), ( )()() -> open 괄호가 1개 나오는 경우

재귀를 통해 각 케이스 별로 괄호를 생성해서 배열에 담아 반환하는 것을 볼 수 있다.
 
*/