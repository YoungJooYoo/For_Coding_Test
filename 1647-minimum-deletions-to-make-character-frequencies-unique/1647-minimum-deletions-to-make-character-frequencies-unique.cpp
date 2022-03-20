class Solution {
public:
	int minDeletions(string s) 
    {
		unordered_map<char, int> alphabet_freq; // 알파벳 빈도수 체크
		unordered_map<int, int> mp; // 빈도수가 얼마나 나왔는지 체크, 즉 중복의 빈도수가 있는지 확인하는 hash
		int count = 0;
        
        /* 알파벳의 빈도수를 체크한다. */
        for (const char& i : s) {
            alphabet_freq[i]++;
        }
		
		for (auto& freq : alphabet_freq) {
			while (mp.find(freq.second) != mp.end() && freq.second > 0) { // 알파벳 빈도수를 넣은 값 freq.second가 mp에 존재한다면, mp에 존재하지 않는 값이 나올떄까지 마이너스를 한다.
				freq.second--; // 알파벳 빈도수를 감소시킨다. 조건에따라 빈도수는 1까지 떨어뜨려야한다.
				count++; // 감소시켰으므로 몇번 감소시켰는지 체크하는 count를 ++
			}
			mp[freq.second]++; // 알파벳의 빈도수를 해시에 넣는다, 해당 빈도수가 겹치는 것이 있는지 확인하기 위해한다.
		}
        
		return count;
	}
};