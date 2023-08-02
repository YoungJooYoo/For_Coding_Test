class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        const size_t ARR_SIZE = nums.size();
        vector<int> result(ARR_SIZE, -1);
        stack<int> st;
        
        if (ARR_SIZE == 0) {
            return result;
        }
        
        // 뒤에서부터 원소 스택에 넣어두기.
        for (int i = ARR_SIZE - 1; i >= 0; i--) {
            st.push(nums[i]);
        }
        
        for (int i = ARR_SIZE - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop(); // 현재 비교하는 숫자보다 작은 수는, pop으로 숫자 전부 제거
            }            
            if (!st.empty()) {
                result[i] = st.top(); // 스택이 비어있지 않은 조건에서, top에 nums[i]보다 큰 값 있으면 정답 배열에 넣는다
            }
          st.push(nums[i]); // 비교한 현재 수 다시 넣는다(저장개념, 재활용)
        } 
        return result;
    }
}; 