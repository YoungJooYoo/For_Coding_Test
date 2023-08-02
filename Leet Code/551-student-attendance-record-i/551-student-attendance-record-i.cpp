class Solution {
public:
    bool checkRecord(string s) 
    {
		const size_t str_len = s.size();
		int count_absent = 0;
		int count_late = 0;

		for (size_t i = 0; i < str_len; i++) {
			if (s[i] == 'A') {
				count_absent++;
				if (count_absent == 2) {
					return false;
				}
			}
			else if (s[i] == 'L') {
				size_t j = i + 1;
				count_late = 1;
				while (j < str_len && j <= i + 2) {
					if (s[j] == 'L') {
						count_late++;
					}
					j++;
				}
				if (count_late == 3) {
					return false;
				}
			}
		}

		return true;
    }
};