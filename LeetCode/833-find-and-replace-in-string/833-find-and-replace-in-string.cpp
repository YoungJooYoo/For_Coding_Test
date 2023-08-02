class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) 
	{
		map<int, pair<string, string>> mp;
		string result = s;
		int dx = 0; // 문자열에 인덱스 계산에 사용될 길이 변수

		/* 맵에 인덱스 -[원래 문자열, 바뀔문자열] 매핑 작업을 한다. */
		for (size_t i = 0; i < indexes.size(); i++) {
			mp[indexes[i]] = make_pair(sources[i], targets[i]);
		}

		for (const auto& itr : mp) {
			auto idx = itr.first;
			auto rec = itr.second;
			if (s.substr(idx, rec.first.size()) == rec.first) { // substr함수를 이용해 s문자열 indicies값을 사용해 시작 인덱스부터 substr만들고 비교
				result.erase(idx + dx, rec.first.size()); // 대체될 문제열을 지우고
				result.insert(idx + dx, rec.second); // 새로운 문자열을 넣어 대체시킨다.
				dx += rec.second.size() - rec.first.size();
			}
		}

		return result;
	}
};

/*
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) 
	{
		map<int, pair<string, string>> mp;
		string result = s;
		int distance = 0;

		for (size_t i = 0; i < indices.size(); i++) {
			mp[indices[i]] = make_pair(sources[i], targets[i]);
		}

		for (const auto& itr : mp) {
			auto index = itr.first;
			auto str_table = itr.second;
			if (s.substr(index, str_table.first.size()) == str_table.first) {
				result.erase(index + distance, str_table.first.size());
				result.insert(index + distance, str_table.second);
				distance = distance + str_table.second.size() - str_table.first.size();
			}
		}
		
		return result;
	}
};
*/