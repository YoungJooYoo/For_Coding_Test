class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, vector<int>> mp; 
        
        for(const auto& piece : pieces) {
            mp[piece[0]] = piece; // 배열의 시작원소 - 부분배열 매핑
        }
        
        vector<int> result;
        for(const auto elem : arr) { 
            if (mp.find(elem) != mp.end()) { // 원소가 검색되면, 해당 원소시작점부터 부부배열 원소를  찾아 넣는다.
                result.insert(result.end(), mp[elem].begin(), mp[elem].end());
            }
        }
        
        return result == arr ? true : false; // 만들어진 배열과 원본 배열이 같은지 비교
    }
};

// https://leetcode.com/problems/check-array-formation-through-concatenation/description/
