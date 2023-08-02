class Solution {
public:
	string freqAlphabets(string s) 
    {
		unordered_map<string, char> m;
        string result;

        // 문자 매핑
		for(int i = 1; i < 10; i++) {
			string temp = to_string(i);
			m[temp] ='a' + i - 1;
		}
		for (int i = 10; i <= 26; i++){
			string temp = to_string(i) + '#';
			m[temp]='j' + i - 10;
		}

		for (int i = s.size() - 1; i >= 0; i--){
			if (s[i] == '#'){
				string cur = s.substr(i - 2, 3);
				result += m[cur];
				i -= 2;
			}
			else {
				string ss = "a";
				ss[0] = s[i];
				result += m[ss];
			}
		}

		reverse(result.begin(),result.end());

		return result;
	}
};

// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/description/
