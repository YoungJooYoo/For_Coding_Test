class Solution {
public:
    bool equalFrequency(string word) 
    {
        if (word.size() <= 2) {
            return true;
        }

        unordered_map<char, int> freq;
        vector<int> diff;

        for (const auto& ch : word) {
            ++freq[ch];
        }

        for (const auto& elem : freq) {
            diff.push_back(elem.second);
        }
        sort(diff.begin() , diff.end()); // 정렬 후  최소 -> 최대 값 순서로 나열된 정렬된 배열로 만든다.

        const size_t n = diff.size();
        if (n == 1)  return true ;
        else if (diff[0] == diff[n - 2] && diff[n - 2] == diff[n - 1] && diff[0] == 1)  return true; // 모든 원소가 1인 경우
        else if (diff[0]== diff[n - 2] && diff[n - 1] - diff[0] == 1)   return true; // 최대값 원소랑  최소값 원소 차이가 1인 경우
        else if (diff[0] == 1 && diff[1] == diff[n - 1])  return true;
        
        return false;
    }
};

// https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/
