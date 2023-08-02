class Solution {
public:
    string addStrings(string num1, string num2) 
    {
    	string result;
		int sum = 0;

		// sum == 0이면, 주어진 배열에서 덧셈이 모두 끝난 경우 => 종료조건
		while (num1.empty() == false || num2.empty() == false || sum != 0) {
			if (num1.empty() == false) { 
				sum = sum + num1.back() - '0'; // 문자를 숫자화 작업
				num1.pop_back(); //
			}
			if (num2.empty() == false) {
				sum = sum + num2.back() - '0';
				num2.pop_back();
			}
			result.push_back((sum % 10) + '0'); // 뒷자리 계산부터 쌓기, int -> char 변환, carry 값 고려하지 않고 덧셈 누적
			sum = sum / 10; // Carry값 처리
		}

		reverse(result.begin(), result.end()); // 뒷자리부터 계산 된 것이 앞에 있으니 reverse

		return result;
    }
};