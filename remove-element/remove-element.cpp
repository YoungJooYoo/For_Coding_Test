class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        vector<int> solution; // 정답을 담을 벡터
        
        // 배열에 정답만 답는다.
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                cout << "nums[" << i << "] : " << nums[i] << endl;
                solution.push_back(nums[i]);
            }
        }
        
        // 정답 배열의 값을 원본 배열에 복사한다.
        for (size_t i = 0; i < solution.size(); i++) {
            nums[i] = solution[i];
        }
        
        // 정답배열 길이가 정답 원소의 갯수
        return solution.size();
    }
};