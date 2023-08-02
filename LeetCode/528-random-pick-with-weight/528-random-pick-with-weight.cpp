class Solution {
public:
    Solution(vector<int>& w) : weightSum(0), sizeOfInput(w.size())
	{
        for (size_t i = 0; i < sizeOfInput; ++i) {
            userMap.push_back(make_pair(weightSum, weightSum + w[i] - 1));
            weightSum += w[i];
        }
    }
    
    int pickIndex() 
	{
        long long targetKey = rand() % weightSum;
        size_t left = 0;
        size_t right = sizeOfInput - 1;

		// 이진탐색 실행
        while (left <= right) {
            size_t mid = left + (right - left) / 2;

            if (userMap[mid].first <= targetKey && userMap[mid].second >= targetKey) {
                return mid;
            }
            else if (userMap[mid].first > targetKey) {
                right = mid - 1;
            }
            else if (userMap[mid].second < targetKey) {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    const size_t sizeOfInput;
    long long weightSum; 
    vector<pair<long long, long long>> userMap;
};

// 풀이 참고
// https://lessbutbetter.tistory.com/entry/LeetCodeMediumC%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B4-528-Random-Pick-with-Weight