class Solution {
public:
    vector<int> minOperations(string boxes) 
	{
	    int sum = 0;
		int ballSeen = 0;
        const size_t BOXES_LENGTH = boxes.size();
		vector<int> result(BOXES_LENGTH, 0);
                
        for (size_t i = 1; i < BOXES_LENGTH; ++i) {
		    if (boxes[i - 1] == '1') { 
			    ballSeen++;
			}
			sum += ballSeen;
			result[i] += sum;
		 }

		 sum = 0;
		 ballSeen = 0;
        
		 for (int i = BOXES_LENGTH - 2; i >= 0; --i) {
			 if (boxes[i + 1] == '1') { 
				 ballSeen++;
			 }
			 sum += ballSeen;
			 result[i] += sum;
		 }
		 
		return result;
    }
};

/* 풀이법 :
예시 2번을 보면

첫번째 원소 0으로부터 첫번째 1이 나오는 간격이
2
그 다음1은, 4
마지막 1은 5이다

2 + 4 + 5 = 11
답이 그래서 11부터 시작한다.
즉, 1의 간격들의 합을 누적해서 반환하는게 문제의 요지다.

*/