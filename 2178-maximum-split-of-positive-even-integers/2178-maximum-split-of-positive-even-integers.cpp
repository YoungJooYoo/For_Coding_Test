class Solution {
public:
    vector<long long> maximumEvenSplit(const long long FINAL_SUM) 
    {
        vector<long long> ans;
        long long i = 2;
        long long sum = 0;
        
        if (FINAL_SUM % 2 != 0) {
            return ans;
        }
        
        while (sum + i <= FINAL_SUM) {
            ans.push_back(i);
            sum += i; // 누적값을 체크한다.
            i += 2; // 배열의 원소는 짝수므로 +2 씩
        }
		
		const size_t ARRAY_SIZE = ans.size(); // 배열의 마지막 원소를 구하기
        ans[ARRAY_SIZE - 1] += (FINAL_SUM - sum); 
        
        return ans;
    }
};