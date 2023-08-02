class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        map<int, int> freq;
        int rounds = 0;

        for (const auto& task : tasks) {
            ++freq[task];
        }

        for (auto elem : freq) {
            if (elem.second == 1) {
                return FAIL;
            }
            // 몫 = 라운드, 나머지가 2라면, ex) 최소숫자 4로 예시들면 2+2로 2라운드 가능
            rounds += (elem.second / 3) + (elem.second % 3 != 0);
        }

        return rounds;
    }
    
private:
    enum { FAIL =  -1 };
};

// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
