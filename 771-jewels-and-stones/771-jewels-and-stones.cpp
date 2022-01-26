class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
	{
		int sum = 0;
		unordered_map<char, int> mp; // 문자-카운트 형태로 사용할 자료구조

		/* jewles의 원소를 하나씩 분해해서 hash에 넣는다. */
		for (const char& ch : jewels) {
			mp[ch];
		}

		// stones의 원소를 하나씩 뺴오면서, 아까 저장해둔 mp의 알파벳과 일치하는지 비교
		for (const char& ch : stones) {
			if (mp.find(ch) != mp.end()) { // ch가 존재 한다면, mp.second인 알파벳카운트에 + 1.
				mp[ch]++;
			}
		}

		// 위에서 알파벳별로 카운팅이 끝나면, 카운트만 모아서 최종 합을 구한다.
		for (const auto& count : mp) {
			sum = sum + count.second;
		}
		
		return sum;
    }
};