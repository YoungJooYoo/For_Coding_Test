class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        const size_t arr_length = arr.size();
        vector<int> result(arr.size());
        int max = INT_MIN;
        
        // 마지막 원소는 무조건 -1이 들어간다.
        result[arr_length - 1] = -1;
        
        for (int i = arr_length - 1; i > 0; i--) {
            if(arr[i] < max) {
                result[i - 1] = max;
            }
            else{
                result[i - 1] = arr[i];
                max = arr[i];
            }
        }
        
        return result;
    }
};