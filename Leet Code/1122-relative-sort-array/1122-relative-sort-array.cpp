class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        vector<int> result; // 해쉬는 순서가 꼬일 수 있어서, 배열로 순서 보장을 받는다.
        vector<int> temp;
        
        for (const auto& arr : arr1) {
            mp1[arr]++;
        }
        
        for (const auto& arr : arr2) {
            if (mp1.find(arr) != mp1.end()) { // 해당원소가 mp1에 존재하면
                while (mp1[arr] != 0) {
                    result.push_back(arr);
                    mp1[arr]--;
                }
            }
        }
        
        for (auto& elem : mp1) {
            while(elem.second != 0) {
                temp.push_back(elem.first);
                elem.second--;
            }
        }
        
        sort(temp.begin(), temp.end());
        result.insert(result.end(), temp.begin(), temp.end());
        
        return result;
    }
};