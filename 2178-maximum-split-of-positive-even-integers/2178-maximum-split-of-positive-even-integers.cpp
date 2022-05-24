class Solution {
public:
    vector<long long> maximumEvenSplit(const long long FINAL_SUM) 
    {
        vector<long long> ans;
        long long i = 2;
        long long crSum = 0;
        
        if (FINAL_SUM % 2 != 0) {
            return ans;
        }
        
        while (crSum + i <= FINAL_SUM) {
            ans.push_back(i);
            crSum += i;
            i += 2;
        }
		
		
		const size_t ARRAY_SIZE = ans.size(); // add remaining difference to the last value in answer list
        ans[ARRAY_SIZE - 1] += (FINAL_SUM - crSum);
        
        return ans;
    }
};