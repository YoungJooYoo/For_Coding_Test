class Solution {
public:
	bool matchString(const string& s, const string& word)
	{
		size_t word_length = 0;

		for (size_t i = 0, j = 0; i < s.size() && j < word.size(); i++) {
			if (s[i] == word[j]) {
				j++;
				word_length++;
			}
		}

		return (word_length == word.size()) ? true : false;
	}

	int numMatchingSubseq(string s, vector<string>& words) 
	{
		unordered_map<string, int> mp;
		int count = 0;

		for (const auto& word : words) {
			if (mp.find(word) != mp.end()) {
				count = count + mp[word];
			} 
			else {
				mp[word] = matchString(s, word);
				count = count + mp[word];
			}
		}

		return count;
	}
};