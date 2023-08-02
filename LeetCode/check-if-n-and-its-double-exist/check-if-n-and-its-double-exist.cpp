class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        for (size_t i = 0; i < arr.size() - 1; i++) {
            for (size_t j = i + 1; j < arr.size(); j++) {
                if(arr[j] == (2 * arr[i]) || arr[i] == (2 * arr[j])) {
                    return true;
                }
            }
        }
        
        return false;
    }
};