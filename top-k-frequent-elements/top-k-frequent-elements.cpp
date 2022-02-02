class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		vector<int> ans;
		unordered_map<int, int> mp;
		priority_queue<pair<int, int>> pq; // count - key

		// push each nums to hash table mp, num-count
		// 해시 테이블에 숫자-카운팅 관계로 빈도수 체크
		for (const int& num : nums) {
			mp[num]++;
		}

		// 빈도수-숫자 로 매핑을 바꾸고, 빈도수를 자동 정렬하기 위해
		// 우선순위 큐를 사용해 카운트-숫자로 넣는다.
		for (auto& [key, count] : mp) {
			pq.push({count, key});
		}
		
		// k번만큼, 우선순위큐는 가장위가 가장 큰값이므로
		// 가장 큰 빈도수부터 점검해 카운티-숫자, 즉 second값 숫자를
		// 벡터에 집어넣고, 큐를 하나씩 제거한다.
		while(k > 0) {
			ans.push_back(pq.top().second);
			pq.pop();
			k--;
		}

		return ans;
    }
};