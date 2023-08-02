class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) 
    {
        return  (a.second == b.second) ? a.first>b.first : a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        vector<pair<int, int>> nums_freq;
        vector<int> result;
        
        if (nums.size() == 1) { 
            return nums;
        }
        
        // 해시 자료구조 맵을 사용해 숫자 중복을 제거하고, 빈도수를 체크한다.
        for (const int& num : nums) {
            mp[num]++;
        }
        
        // map은 second 기준으로 정렬 될 수 없으니, vector에 복사 후 정렬한다.
        for (const auto& elem : mp)  {
            nums_freq.push_back(elem);
        }
        
        // cmp 등을 이용해 second 값 (빈도수), 기준으로 정렬한다.
        sort(nums_freq.begin(), nums_freq.end(), cmp);
        
        // 빈도수가 낮은 숫자부터 오름차순 정렬된 배열에서 first(숫자) , second 빈도 값만큼 정답배열에 넣는다.
        for (auto num : nums_freq) {
            for (int i = 0; i < num.second; i++) {
                result.push_back(num.first);
            }
        }
        
        return result;
    }
};