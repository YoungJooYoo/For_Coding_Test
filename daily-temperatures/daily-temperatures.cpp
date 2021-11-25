class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        const size_t arr_length = temperature.size();
        stack<int> s;
        vector<int> ans(arr_length, 0);
        size_t j;
        
        for (size_t i = 0; i < arr_length; ++i) {
            while ((s.empty() == false) && (temperature[s.top()] < temperature[i])) { // 스택이 비지 않고, 스택에 저장된 온도와 지금 온도 비교시 조건이 맞으면
                j = s.top(); // j에 스택에 저장된 값을 주고 
                s.pop(); 
                ans[j] = i - j; //
            }
            s.push(i); // 인덱스를 스택에 저장, temp current > temp next 시에 스택에 계속 쌓인다
        }
        
        return ans;
    }
};

/*

풀이법 :
ans 배열에 모든 값을 0으로 세팅하고 (0은 온도 따스한 날이 없다 의미)
온도 배열의 앞뒤 값을 비교해 앞이 작은 경우 인덱스를 스택에 넣어둔다.
해당 인덱스의 온도와, 현재 온도를 비교해 인덱스 차이를 vector에 집어 넣어서
답을 구한다.

*/