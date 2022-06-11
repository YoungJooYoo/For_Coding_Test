class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        const int ARR_SIZE = nums.size();
        int total = 0;
        int current = 0;
        int ans = -1;
        int left = 0;
        
        // 전체 합 구하기
        for (const int& num : nums) {
            total += num;
        }

        // 인덱스 관점에서 right는 끝 인덱스, left는 뒤에서 따라오는 시작 인덱스이다.
        for (int right = 0; right < ARR_SIZE; right++) {
            current += nums[right]; // 인덱스 0부터 순차적 누적값을 구한다.
            while (current > total - x && left <= right) { // current > total -x 조건 : 
                current -= nums[left]; // 누적된 값에서 앞부분의 값을을 빼온다.
                left++;  // left 값을 앞으로 땡겨온다
            }
            if (current == total - x) { // oo xxx oo -> 우린x의 길이를 구함, x가 길어야 o길이가 짧다.
                int length = right - left + 1;
                ans = max(ans, length); // 길이가 길어야 무제에서 요구 하는 최소 길이가 나온다.
            }
        }
        
        if (ans != -1) {
            return ARR_SIZE - ans;
        }
        
        return -1;
    }
};