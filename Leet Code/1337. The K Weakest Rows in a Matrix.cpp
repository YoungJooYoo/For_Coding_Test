class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        const size_t n = mat.size();
        set<pair<int,int> > s; // pair : count - index
        vector<int> result;
    
        for (size_t i = 0; i < n; ++i) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1); // count 1
            s.insert({cnt, i});
        }
        
        auto itr = s.begin();
        for (size_t i = 0; i < k; ++i) {
            result.push_back(itr->second);
            ++itr;
        }
        
        return result;
    }
};

/*

풀이법 :
군인의 수가 가장 많은 행을 순서대로 나열하기
 
 */

// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
