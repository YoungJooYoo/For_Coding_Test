class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int temp_value = arr[0];
        int max_value = arr[0]; // 예제 2번 1개 들어오는 경우 대비해서 1번 원소부터 넣는다.
        
        for (size_t i = 1; i < arr.size(); i++) {
            temp_value = max(arr[i], (temp_value + arr[i]));
            max_value = max(max_value, temp_value);
        }
        return max_value;
    }  
};