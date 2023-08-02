class Solution {
public:
    int singleNumber(vector<int>& nums) 
	{
        unordered_map<int, int> map;

		for (const int& num : nums) {
			map[num]++;
		}

		for (auto itr = map.begin(); itr != map.end(); itr++) {
			if (itr->second == 1) {
				return itr->first;
			}
		}

		return 0;
    }
};