class Solution {
public:

    int recursive(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target < 0) return 0;
        if (dp[target] != -1) return dp[target];
        
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            count += recursive(nums, target - nums[i], dp);
        }
        
        dp[target] = count;
        
        return count;
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target + 1, -1); // dp배열의 인덱스가 원소이다.
        dp[0] = 1;
        
        recursive(nums, target, dp);
        
        return dp[target];
    }
};

/*
풀이법 : 
dp 배열의 인덱스 즉, 
해당 인덱스 숫자를 만들기위한 방법의 수를 계산한다.


즉, index 0 1 2 3 4
    count 1 1 2 4 7
index 4번, 즉 숫자 4를 위해 나올 수 있는 조합의 수는
1 + 2 + 4 = 7이 된다.


*/