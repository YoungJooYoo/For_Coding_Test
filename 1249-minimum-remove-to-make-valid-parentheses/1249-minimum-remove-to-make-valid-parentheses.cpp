class Solution {
public:
    string minRemoveToMakeValid(string s) 
	{
		stack<int> parenthese_pos; 

		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == '(') { // ( 일경우 문자열의 인덱스를 저장
				parenthese_pos.push(i);
			}
			else if (s[i] == ')') { // () 짝이 맞으면 pop
				if (!parenthese_pos.empty() && s[parenthese_pos.top()] == '(') {
					parenthese_pos.pop();
				}
				else {
					parenthese_pos.push(i);
				}
			}
		}

		/* () 짝이 맞지 않는 인덱스 부분만 제거해서 스트링을 다시 반환한다. */
		while (!parenthese_pos.empty()) {
			s.erase(parenthese_pos.top(), 1);
			parenthese_pos.pop();
		}

		return s;
	}
};