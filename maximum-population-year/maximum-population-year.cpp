class Solution 
{
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        unsigned int pop_year[2050-1950+1] = {0}; // size = 101
        unsigned int max_val = 0;
        unsigned int cnt = 0;
        unsigned int max_year = 0;
        size_t pop_year_length = sizeof(pop_year) / sizeof(pop_year[0]); // size = 101
        
        // 한쌍으로 이루어진 [출생년도, 사망년도], 주어진 logs에서 인기있는 출생년도, 사망년도 카운팅
        for(size_t i = 0; i < logs.size(); i++) { 
            pop_year[logs[i][0]-1950]++; // 살아 있는 년도는 ++
            pop_year[logs[i][1]-1950]--; // 음수 값을 넣는다. 죽은해는
        }
        
        // 
        for(size_t i = 0; i < pop_year_length; i++) {
            cnt = cnt + pop_year[i]; // cnt 값은 죽은해의 값이 음수라서 year 사이클 한번 돌면 초기화된다.
            if(max_val < cnt) {
                max_val = cnt;
                max_year = i;
            }
        }
        
        return max_year + 1950;  
    }
};