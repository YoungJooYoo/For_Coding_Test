class Solution 
{
public:
    int countsetbits(int n)
    {
        int count = 0;
        
        while (n != 0)
        {
            if (n % 2 != 0) {
                count++; // 비트 1이 존재
            }
            n /= 2;
        }
        
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) 
    {
        map<int, vector<int>> mp; // [key 비트 수]-[value 숫자들 ] 
        vector<int> result;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            mp[countsetbits(arr[i])].push_back(arr[i]); // 1의 비트의 갯수에 따라 분류해서 맵에 저장
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            for (const int& elem : it->second) {
            result.push_back(elem);
            }
        }
        
        return result;
    }
};