class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
	{
		int result = 0;
		unordered_map<int,int> mp;

		// nums1, num2 각각 원소를 더해 나오는 모든 조합을 계산한다.
		// a + b    part.
		for (const int& a : nums1) {
			for (const int& b : nums2) {
				mp[a + b]++;
			}
		}

		// part c + d part
		for (const int& c : nums3) {
			for (const int& d : nums4) {
				if (mp.find(-(c + d)) != mp.end()) { // 해시안에 -(a+b)가 존재하는지, 존재하면 몇개가 존재하는지 카운팅
					result = result + mp[-(c + d)];
				}
			}
		}

		return result;
	}
};
// idea: a+b+c+d = 0  =>  a+b = -(c+d) ;
// store a+b in hash map for first two array combinations
// later for last two array combinations check if sum exist in array