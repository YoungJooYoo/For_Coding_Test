class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
        const size_t nums_length = nums.size();
        set<vector<int>> ans;
		vector<int> temp;
		int k;
		int l;

		if (nums_length < 4) {
			return {};
		}

		sort(nums.begin(),nums.end()); // 정렬 후 좌 : 음수 우 : 양수 순서 만들기 가능
		
		for (size_t i = 0; i <= (nums_length -1) - 3; i ++) {  // -1 -> last index, -3 j k l 때문
			for (size_t j = i + 1; j <= (nums_length - 1) - 2; j ++) {
				k = j + 1; // j 다음
				l = nums_length - 1; // 마지막 인덱스
				long long first = nums[i] + nums[j];
				while (k < l) {
					long long sum = first + nums[k] + nums[l];
					if (sum == target) {
						temp = {nums[i], nums[j], nums[k], nums[l]};
						ans.insert(temp);
						temp.clear();
						k++;
					}
					else if (sum < target) {
						k++; // sum보다 크면 작은 값을 증가 시켜 찾는다.
					}
					else { // sum > target
						l--; // 큰 값을 내리고
					}
				}
			}
		}

        vector<vector<int>> result;
		for (const auto& element : ans) {
			result.push_back(element);
		}
        return result;
    }
};