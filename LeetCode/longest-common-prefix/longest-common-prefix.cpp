class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        size_t min_length = INT_MAX;
        string answer = "";

        // 예외처리, 조건에 안맞는 것
        if (strs.size() < 1 || strs.size() > 200) {
            return answer;
        }
        
        // 모든 문자열에 공통 문자열이 존재해야 하므로, 1번째 문자열을 대표로 나머지 문자열과 비교한다. 
        for (size_t i = 0; i < strs[0].size(); i++) {
            size_t count = 1; //
            size_t j = 1; // 문자열 1번 [0]과 2번[1] 비교 시작을 위해
            int temp = strs[0][i]; // 첫번쨰 스트링 문자열

            // 입력받은 문자열의 갯수 만큼 and 1번째 문자열과 2번째 문자열 3, 4 ...... n번째 문자열 까지 and n번째 문자열의 0번째 원소부터 temp(0번째 비교할 대표 스트링)와 일치하는지
            // 이 조건이 다 맞으면 ++로 카운트시작
            for (; j < strs.size() && i != strs[j].size() && strs[j][i] == temp; j++) {
                count++;
            }
            // 일치하는 문자열 덧붙이기
            if (count == strs.size()) {
                answer = answer + strs[0][i];
            }
            else {
                break;
            }
        }

        return answer;
    }
};