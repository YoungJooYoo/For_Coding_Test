class Solution 
{
public:
    int missingElement(vector<int>& nums, int k) 
    {
        int result = nums[0] + k; // 미리 k를 더하고 시작, 배열 조건이 길이가 1이상이므로.
        
        // 1번 인덱스부터 탐색
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > result) { // 이미 k가 더해진 result보다 배열의 원소가 크면 반환  
                return result;
            }
            else {
                result++;
            }
        }
        
        return result;
    }
};