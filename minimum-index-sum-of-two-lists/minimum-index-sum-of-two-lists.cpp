class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> map;
        int mini = INT_MAX;
        
        for(int i=0; i<list1.size(); i++){
            map[list1[i]] = i;
        }
        for(int i=0; i < list2.size(); i++){
            if (map.find(list2[i]) != map.end()){
                if (map[list2[i]]+i < mini){
                    mini = map[list2[i]]+i;
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if (map[list2[i]]+i == mini){
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
    }
};

/*

풀이법 :
문자열 묶음 단위 비교

*/