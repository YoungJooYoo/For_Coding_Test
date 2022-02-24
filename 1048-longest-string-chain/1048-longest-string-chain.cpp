class Solution {
public:
    int longestStrChain(vector<string>& words) 
	{	
		// words의 길이 기준으로 오름차순 정렬, 람다식 이용
		sort(words.begin(), words.end(), [](const string& first, const string& second)
		{
			return first.size() < second.size();
		});

        map<string, int> mp;
        int result = 0;

        for (const string& word : words) {
            int longest = 0;
            for (size_t i = 0; i < word.length(); i++) {
                string sub = word.substr(0, i) + word.substr(i + 1, word.length()); // ex) abcdef -> ab + (cdef + null character) 이렇게 2문자열로 나눈다.
                longest = max(longest, mp[sub] + 1);   
            }
            mp[word] = longest;
            result = max(result, longest);
        }

        return result;
    }
};

// https://leetcode.com/professionalusername/