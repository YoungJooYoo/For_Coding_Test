class Solution {
public:
    void recursive_backtracking(int index, int arr_size, vector<int> nums)
    {
        if (index == arr_size) {
            result.push_back(nums);
            return;
        }
        
        for (size_t i = index; i < arr_size; i++) {
            if (index == i || nums[index] != nums[i]) {
                swap(nums[i], nums[index]);
                recursive_backtracking(index + 1, arr_size, nums);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        recursive_backtracking(0, nums.size(), nums);
        
        return result;
    }
    
private:
    vector<vector<int>> result;
};


/*
풀이법 :

재귀함수할때 레퍼런스로 받지 않아야, 
swap되지 않은 배열로 돌아갈 수 있다.

조건문에, for문이 시작할 경우나, 배열의 원소값이 같지 않으면
swap후 재귀를 돌리는데, 이는 중복적인 답을 건너뛰기 위한 조건이다.

*/
