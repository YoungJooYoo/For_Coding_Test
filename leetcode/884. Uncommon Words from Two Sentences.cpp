class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        	stringstream ss1(s1); // 스트링을 공백 기준으로 분리
            stringstream ss2(s2); 
	        string str1;
            string str2;
            unordered_map<string, int> freq;
            vector<string> result;

	        while (ss1 >> str1) {
                freq[str1]++;
            }
            while (ss2 >> str2) {
                freq[str2]++;
            }
            
            for (const auto& elem : freq) { // 해시테이블에 넣고, 1개만 나온 것은 중복이 없는 것이므로 유니크
                if (elem.second == 1) result.push_back(elem.first);
            }

            return result;
    }
};

// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
