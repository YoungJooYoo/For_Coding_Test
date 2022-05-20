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

즉 시작은 ( 이 괄호 부터 가능하며, 이 괄화 갯수에 따라 호출되는 재귀 함수를 통해
*/