class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        const size_t arr_length = arr.size();
        vector<int> dp(arr_length, INT_MAX);
        
        int sum = 0;      
        int ans = INT_MAX;
        int len = INT_MAX;     
        size_t start = 0;
        size_t end = 0;
        
        for (end = 0; end < arr_length; end++) {
            sum += arr[end]; // 배열의 원소를 순서대로 sum에 누적한다. 
            
            while (sum > target) { // 누적값이 target보다 크다면, 같거나 작을때까지 배열의 앞에서부터 누적 감산한다.
                sum -= arr[start];
                start++;
            }
            
            if (sum == target) { // target과 같은 sum을 찾은경우
                int curr_len = end - start + 1; // 현재 start -> end 까지 인덱스 사이의 길이를 구한다. 부분배열의 길이를 구하는 것
                if (start > 0 && dp[start - 1] != INT_MAX) {
                    ans = min(ans, curr_len + dp[start - 1]); // ans는 2개의 하위 배열 길이 또는 현재 길이 + 마지막 최소 길이(dp에 저장됨)
                } 
                len = min(curr_len, len); 
            }
            dp[end] = len;  // dp stores the previous min length
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};