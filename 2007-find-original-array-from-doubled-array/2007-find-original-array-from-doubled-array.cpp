class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) 
	{
        vector<int> ans;
		unordered_map<int,int> mp;
        const size_t changed_size = changed.size();

        if (changed_size == 1) {
			return {};
		}

		sort(begin(changed),end(changed));

        for (const auto& num : changed) { // 숫자가 얼마나 나오는지 빈도체크
			mp[num]++;
		}

        for (const auto& num : changed) {
            if (mp[num] == 0) { // 해당 숫자가 빈도수가 0이면 pass.
				continue;
			}
            else if (mp[2 * num] == 0 || mp[0] == 1) { // 숫자 0은 배수가 없으므로 예외, 혹은 2배 원소가 없다면 return
				return {};
			}
            else {
                ans.push_back(num);
            }
            mp[2 * num]--; // 2배 원소를 찾았으므로 카운트를 제거한다.
			mp[num]--; // 2배 원소를 찾았으므로 카운트를 제거한다.
        }

        return ans;
    }
};


/*
풀이법 :
주어진 배열에서 각원소의 숫자가 나오는 빈도를 체크한다.
여기서 0은 어떤수의 2배수가 될 수 없으므로 발견하면 빈 배열을 return한다.

*/

/*
class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) 
	{
		vector<int> result;
		const size_t changed_size = changed.size();
		map<int, int> mp;

		if (changed_size == 1) {
			return {};
		}

		sort(begin(changed), end(changed));

		for (const int& num : changed) {
			mp[num]++;
		}

		for (const int& num : changed) {
			if (mp[num] == 0) {
				continue;
			}
			else if (mp[2 * num] == 0 || mp[0] == 1) {
				return {};
			}
			else {
				result.push_back(num);
			}
			mp[num]--;
			mp[2 * num]--;
		}

		return result;
	}
};
*/