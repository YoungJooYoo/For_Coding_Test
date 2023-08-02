class Solution {
public:
    string multiply(string num1, string num2) 
	{
        if (num1 == "0" || num2 == "0") {
			return "0";
		}
        
        vector<int> res(num1.size() + num2.size(), 0); // 99 * 99 = 9801 (4자리) 
        //res[0,0,0,0] 9,9   9,9
        for (int i = num1.size() - 1; i >= 0; i--) { // 1의 자리부터 계산
            for (int j = num2.size() - 1; j >= 0; j--) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // 맨 끝자리 1의 자리부터 채워넣기
                res[i + j] += res[i + j + 1] / 10; // carray 값을 다음 자리수에 계산
                res[i + j + 1] %= 10; // 1의 자리 숫자 계산
            }
        }
        
        size_t i = 0;
        string ans = "";
		for (auto itr : res) {
			cout << itr << endl;
		}
        while (res[i] == 0) { // 앞자리가 0인 것을 skip하기 위해
			i++;
		}
        while (i < res.size()) { // 0이 스킵된 index부터 string으로 변환
			ans += to_string(res[i]);
			i++;
		}
        
        return ans;
    }
};