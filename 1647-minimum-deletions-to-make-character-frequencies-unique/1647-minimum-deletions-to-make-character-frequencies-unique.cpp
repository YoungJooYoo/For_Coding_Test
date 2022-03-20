class Solution {
public:
	int minDeletions(string s) 
    {
		unordered_map<char, int> alphabet_freq;
		unordered_map<int, int> mp;
		int count = 0;
        
        /* 알파벳의 빈도수를 체크한다. */
        for (const char& i : s) {
            alphabet_freq[i]++;
        }
		
		for (auto& freq : alphabet_freq) {
			while (mp.find(freq.second) != mp.end() && freq.second > 0) { // 알파벳 빈도수를 넣은 값 freq.second가 mp에 존재한다면,
				freq.second--; // 알파벳 빈도수를 감소시킨다.
				count++; // 감소시켰으므로 몇번 감소시켰는지 체크하는 count를 ++
			}
			mp[freq.second]++; //
		}
        
		return count;
	}
};