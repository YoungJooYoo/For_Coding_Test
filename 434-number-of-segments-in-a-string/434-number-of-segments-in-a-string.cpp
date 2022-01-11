class Solution {
public:
    int countSegments(string s) 
    {
		const size_t str_length = s.size();
		int count = 0;

		if (str_length == 0) {
			return 0;
		}
		
        for(size_t i = 0; i < s.length(); i++) {
            if((s[i] != ' ') && ((s[i + 1] == ' ') || (s[i + 1] == '\0'))) {
                count++;
            }
        }

		return count; //
    }
};