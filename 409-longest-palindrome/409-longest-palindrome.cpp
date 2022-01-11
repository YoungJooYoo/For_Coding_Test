class Solution {
public:
    int longestPalindrome(string s) 
	{
        unordered_map<char,int> mp; // 중복 없는 Map 자료구조사용, 알파벳 빈도체크용 
		int ans = 0;
        bool flag = false;

		if(s.size() == 1) {
			return 1;
		}
        
		/* 알파벳 a ~ Z 까지 나온 횟수를 체크 */
        for (auto i : s) {
			mp[i]++;
		}
        
        for (auto map : mp) {
            if (map.second % 2 == 0) { // 짝수로 나온 경우 누적
				ans = ans + map.second;
			}
            else { // 홀수로 나온경우
                ans = ans + map.second - 1; // 홀수나온 원소들 -1씩
                flag = true;
            }
        }
        
		// 총원소의 갯수 == 짝수개 - 모든 홀수개 + 1(홀수) -> aabaa 케이스
        if (flag == true) {
			ans++; 
		}
       
        return ans;
    }
};