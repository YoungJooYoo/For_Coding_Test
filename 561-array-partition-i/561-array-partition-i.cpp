class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
	{
		int result = 0;

        sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size(); i = i + 2) {
			result = result + nums[i];
		}
		
		return result;
    }
};

/*
풀이법 :
배열을 정렬시고 보면 배열은 (1, 2, 3, 4) 
(1, 2) (3, 4)   ==> 1 + 3 = 4
2개씩 묶어서 좌측값만을 더하면 최소값을 이용할 수 있다.
즉, 정렬된 배열에서 2칸씩 띄어서 더하면 된다는 의미이다.
*/