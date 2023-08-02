class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        vector<int> ans(2, -1); // 길이 2의, -1로 초기화된 동적배열 생성
        
        while (start <= end) {
            if (nums[start] == target && nums[end] == target) {  // target을 찾은 경우
                ans[0] = start; // 찾은 두가지 숫자가 모두 해답이므로 ans에 넣는다.
                ans[1] = end;  
                return ans;
            }
            else if (nums[start] != target) { //
                start++;
            }
            else { // nums[end] != target
                end--;
            } 
        }
        
        return ans;
        
    }
};


/*
풀이법 :

정렬된 배열,
O(log n).
이 조건은 즉, 이진탐색을 이야기 하는 것.

2진 탐색으로 풀다, 문제에서 요구하는 시간안에 끝내려면 이진 탐색이 맞으나
트릭으로 다음과 같이 2포인트로 가능
O(n)으로 풀어지는데, 대략 테스트 케이스가 그렇게 길지 않아서 그런 듯

*/