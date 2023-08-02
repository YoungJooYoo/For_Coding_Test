class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        if (n == 0 || n == 1) {
            return n;
        }
        
        /* dp 풀이법 */
        vector<int> arr(n + 1);
        arr[0] = 0; // 인덱스 0과 1을 초기화를 이를 이용해 memoization.
        arr[1] = 1;
        int max_index = 1;
        
        for (size_t i = 2; i <= n; i++) {
            arr[i] = i % 2 == 0 ? arr[i / 2] : arr[i / 2] + arr[i / 2 + 1];
            max_index = max(max_index, arr[i]);
        }
        
        return max_index;
    }
};