class Solution {
public:
    bool isSubsequence(string s, string t) 
	{
        size_t i = 0;
		size_t j = 0;
		size_t count = 0;

		if (s.size() == 0) {
			return true;
		}
	
		while (j < t.size()) {
			if (s[i] == t[j]) {
				i++;
				j++;
				count++;
			}
			else {
				j++;
			}
		}
        
		if (count == s.size()) {
            return true;
        }
        
		return false;
    }
};