class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        set<int> unique_num;
        
        for (const auto& num :nums) {
            if (num != 0) {
                unique_num.insert(num);
            }
        }
        
        return unique_num.size();
    }
};

/*
풀이법 :

문제 특성상, 중복된 숫자는 제거 되도 되므로, set을 사용한다.
숫자를 마이너스해서 최종 원소가 전부 0인 원소를 만드는 횟수는 결국
원소의 갯수의 숫자와 동일하다는 규칙이 나온다.
덧붙여, set에 애초에 의미 없는 값인 0을 제외하고 집어 넣는다.

*/