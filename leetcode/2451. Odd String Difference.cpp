class Solution {
public:
    string oddString(vector<string>& v1) 
    {
        const size_t m = v1[0].size();
        const size_t n = v1.size();
        map<vector<int>, vector<string>> m1; 
    
        /* 
            ex) 
            m1:{
                [{1, 1}] = {"abc"}, 
                [{3, -1}] = {"adc", "wzy"}
            }
        */
        for (const auto& it : v1) {
            vector<int> a;
            for (size_t i = 1; i < m; ++i) a.push_back(it[i] - it[i - 1]);
            m1[a].push_back(it);
        }
        for (const auto& it : m1) { // 길이가 1인 값을 찾으면 된다.
            if(it.second.size() == 1) {
                return it.second[0];
            }
        }

        return "";
    }
};

// https://leetcode.com/problems/odd-string-difference/description/
