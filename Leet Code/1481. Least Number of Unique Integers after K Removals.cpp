class Solution {
public:
    // 주어진 배열 arr에서 정확히 k개의 요소를 제거한 후 남은 고유 정수의 최소 개수를 찾습니다.
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<int> frequencies; // 요소들의 빈도수를 저장할 벡터
        map<int, int> frequencyMap; // 각 요소의 빈도수를 계산하기 위한 맵

        // 배열의 각 요소에 대해 빈도수를 계산합니다.
        for (const int num : arr) {
            frequencyMap[num]++;
        }

        // 맵의 각 요소(빈도수)를 벡터에 저장합니다.
        for (const auto& pair : frequencyMap) {
            frequencies.push_back(pair.second);
        }

        // 빈도수를 오름차순으로 정렬합니다.
        sort(frequencies.begin(), frequencies.end());

        int i = 0; // 제거된 고유 정수의 개수를 추적하기 위한 변수

        // k가 남아있는 동안 가장 낮은 빈도수의 요소부터 제거합니다.
        for (i = 0; i < frequencies.size(); ++i) {
            // k가 현재 요소의 빈도수보다 크거나 같으면 요소를 제거할 수 있습니다.
            if (k >= frequencies[i]) {
                k -= frequencies[i]; // k를 감소시키고 요소를 제거합니다.
            } else {
                break; // 더 이상 제거할 수 없으면 반복을 종료합니다.
            }
        }

        // 벡터의 크기에서 제거된 요소의 개수를 빼서 남은 고유 정수의 개수를 반환합니다.
        return frequencies.size() - i;
    }
};

// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16
